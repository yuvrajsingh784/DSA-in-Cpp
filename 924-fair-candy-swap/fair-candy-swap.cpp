class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;

        for (int x : aliceSizes)
            sumA += x;

        for (int x : bobSizes)
            sumB += x;

        int diff = (sumA - sumB) / 2;

        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());

        for (int a : aliceSizes) {
            int b = a - diff;

            if (bob.find(b) != bob.end())
                return {a, b};
        }

        return {};
    }
};