class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> m;
        vector<int> odd;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) {
                m[1]++;
                odd.push_back(i);
            } else {
                m[0]++;
            }
        }
        odd.push_back(nums.size());
        // for (int i = 0; i < odd.size(); ++i) {
        //     cout << odd[i] << " ";
        // }
        // cout << endl;
        if (m[1] < k) {
            return 0;
        }
        int id = 0;
        int ct = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ct += odd[k + id] - odd[k + id - 1];
            if (nums[i] % 2) {
                m[1]--;
                id++;
            }
            if (m[1] < k) {
                break;
            }
        }
        return ct;
    }
};