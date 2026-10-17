class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            a[i] = {s, nums[i]};
        }

        sort(a.begin(), a.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]] = i;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i].second;
            if (nums[i] == x) continue;

            int j = pos[x];
            pos[nums[i]] = j;
            pos[x] = i;
            swap(nums[i], nums[j]);
            ans++;
        }

        return ans;
    }
};