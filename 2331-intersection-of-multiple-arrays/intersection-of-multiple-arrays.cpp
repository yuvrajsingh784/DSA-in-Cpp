class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int freq[1001] = {0};
        int n = nums.size();
        
        
        for (const auto& arr : nums) {
            for (int num : arr) {
                freq[num]++;
            }
        }
        
        vector<int> result;
      
        for (int i = 1; i <= 1000; i++) {
            if (freq[i] == n) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};