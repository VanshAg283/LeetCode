class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ct = 0;
        int mx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= mx) {
                ct += mx - nums[i] + 1;
                nums[i] = mx + 1;
            }
            mx = nums[i];
        }
        return ct;
    }
};