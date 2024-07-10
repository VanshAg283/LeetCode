class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mp;
        int ans = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            mp[s[end]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += s.length() - end;
                mp[s[start]]--;         
                start++;
            }
        }

        return ans;
    }
};