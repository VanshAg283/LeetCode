class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for (int i = 0; i < s.length(); ++i) {
            mp[s[i]]++;
        }
        int ct = 0;
        int gr_odd = 0;
        for (auto x : mp) {
            if (x.second % 2 != 0) {
                if (x.second > gr_odd) {
                    gr_odd = x.second;
                }
            }
        }
        for (auto x : mp) {
            if (x.second % 2 == 0) {
                ct += x.second;
            } else {
                if (x.second == gr_odd) {
                    ct += gr_odd;
                    gr_odd = INT_MAX;
                } else {
                    ct += x.second - 1;
                }
            }
        }
        return ct;
    }
};