class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        unordered_map<int,int> freq;
        freq[sums[0]]++;
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i];
            if (sums[i] == k) ans++;
            if (freq.find(sums[i] - k) != freq.end()) {
                ans += freq[sums[i] - k];
            }
            freq[sums[i]]++;
        }
        return ans; 
    }
};