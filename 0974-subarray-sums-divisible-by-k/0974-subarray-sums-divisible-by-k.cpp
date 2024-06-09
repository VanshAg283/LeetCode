class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,vector<int>> prefixSums;
        int sum = 0;
        int ct = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) {
                rem = rem + k;
            }
            prefixSums[rem].push_back(i);
            // cout << rem << endl;
        }
        for (auto& i : prefixSums) {
            // cout << i.first << ": ";
            // for (auto j : i.second) {
            //     cout << j << " ";
            // }
            // cout << endl;
            if (i.first == 0) ct += i.second.size();
            int len = i.second.size();
            ct += (len * (len - 1))/2;
        }
        return ct;
    }
};