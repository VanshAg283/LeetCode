class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ct(3);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ct[nums[i]]++;
        }
        int ct0 = 0;
        int ct1 = 0;
        int ct2 = 0;
        for (int i = 0; i < n; ++i) {
            if (ct0 < ct[0]) {
                nums[i] = 0;
                ct0++;
            } else if (ct1 < ct[1]) {
                nums[i] = 1;
                ct1++;
            } else if (ct2 < ct[2]) {
                nums[i] = 2;
                ct2++;
            }
        }
        return;
    }
};