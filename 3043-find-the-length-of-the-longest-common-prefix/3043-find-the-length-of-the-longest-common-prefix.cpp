class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pref;
        for (int i = 0; i < arr1.size(); ++i) {
            int curr = arr1[i];
            while (curr > 0) {
                pref.insert(curr);
                curr = curr / 10;
            }
        }
        int ans = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            int curr = arr2[i];
            while (curr > 0) {
                if (pref.find(curr) != pref.end()) {
                    int len = to_string(curr).length();
                    ans = max(ans, len);
                    break;
                }
                curr = curr / 10;
            }
        }
        return ans;
    }
};