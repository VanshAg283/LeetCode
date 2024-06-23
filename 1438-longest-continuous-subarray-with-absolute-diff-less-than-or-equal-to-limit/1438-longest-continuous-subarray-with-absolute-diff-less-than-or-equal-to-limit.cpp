class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int r = 0;
        multiset<int> s;
        int ct = 0;
        int diff = 0;
        while (r < nums.size()) {
            s.insert(nums[r]);
            diff = *s.rbegin() - *s.begin();
            while (diff > limit) {
                s.erase(s.find(nums[l]));
                diff = *s.rbegin() - *s.begin();
                l++;
            }
            ct = max(ct,r - l + 1);
            r++;
        }
        return ct;
    }
};