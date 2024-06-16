class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 1;
        int index = 0;
        int ans = 0;
        while (sum <= n) {
            if (index < nums.size() && sum >= nums[index]) {
                sum += nums[index];
                index++;
            } else {
                sum *= 2;
                ans++;
            }
        }
        return ans;
    }
};