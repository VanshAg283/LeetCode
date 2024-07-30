class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> pref(s.length());
        vector<int> suff(s.length());
        int ct_a = 0;
        int ct_b = 0;
        for (int i = 0; i < s.length(); ++i) {
            pref[i] = ct_b;
            if (s[i] == 'b') {
                ct_b++;
            }
        }
        for (int i = s.length() - 1; i >= 0; --i) {
            suff[i] = ct_a;
            if (s[i] == 'a') {
                ct_a++;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); ++i) {
            ans = min(ans, pref[i] + suff[i]);
        }
        return ans;
    }
};