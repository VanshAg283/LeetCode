class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ct++;
            }
        }
        if (ct == 0) {
            return 0;
        }
        for (int i = 0; i < ct - 1; ++i) {
            nums.push_back(nums[i]);
        }
        vector<int> window(nums.size());
        window[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            window[i] = window[i - 1] + nums[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int zeros;
            if (nums[i] == 0) {
                zeros = ct - (window[i + ct - 1] - window[i]);
                ans = min(ans, zeros);
            } else {
                zeros = ct - 1 - (window[i + ct - 1] - window[i]);
                ans = min(ans, zeros);
            }
        }
        return ans;
    }
};