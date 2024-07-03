class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int diff = min(nums[nums.size() - 1] - nums[3],
                       nums[nums.size() - 4] - nums[0]);
        diff = min(diff, nums[nums.size() - 2] - nums[2]);
        diff = min(diff, nums[nums.size() - 3] - nums[1]);
        return diff;
    }
};