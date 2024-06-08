class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefixSums(nums.size());
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
            if (prefixSums[i] % k == 0) {
                return true;
            }
        }
        unordered_map<int,int> rem;
        for (int i = 0; i < nums.size(); ++i) {
            int remainder = prefixSums[i] % k;
            if (rem.count(remainder)) {
                if(i - rem[remainder] > 1) {
                    return true;
                }
            } else {
                rem[remainder] = i;
            }
        }
        return false;
    }
};