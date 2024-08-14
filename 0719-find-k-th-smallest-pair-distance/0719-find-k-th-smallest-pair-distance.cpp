class Solution {
private:
    int check(int diff, vector<int>& nums, int k) {
        int ct = 0, left = 0;
        for (int i = 1; i < nums.size(); ++i) {
            while (nums[i] - nums[left] > diff) left++;
            ct += i - left;
        } 
        return (ct >= k);
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, k)) high = mid - 1;
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};