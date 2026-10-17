class Solution {
public:
    static const int MOD = 1e9 + 7;

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql <= l && r <= qr) {
                long long len = r - l + 1;
                long long v = 1;

                sq[node] = (sq[node] + 2LL * sum[node] * v
                            + len * v * v) % MOD;

                sum[node] = (sum[node] + len * v) % MOD;
                lazy[node] = (lazy[node] + v) % MOD;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node] != 0) {
                long long v = lazy[node];

                for (int child : {node * 2, node * 2 + 1}) {
                    long long len = (child == node * 2)
                                    ? mid - l + 1
                                    : r - mid;

                    long long addSum = (len % MOD * v) % MOD;
                    long long addSq = (2LL * v % MOD * sum[child]
                                      + len % MOD * v % MOD * v) % MOD;

                    sq[child] = (sq[child] + addSq) % MOD;
                    sum[child] = (sum[child] + addSum) % MOD;
                    lazy[child] = (lazy[child] + v) % MOD;
                }

                lazy[node] = 0;
            }

            if (ql <= mid)
                self(self, node * 2, l, mid, ql, qr);

            if (qr > mid)
                self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        long long ans = 0;
        unordered_map<int, int> last;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            update(update, 1, 0, n - 1, left, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};