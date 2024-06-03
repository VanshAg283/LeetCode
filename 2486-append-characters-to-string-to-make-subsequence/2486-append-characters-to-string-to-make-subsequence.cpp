class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[l]) {
                l++;
            }
            if (l == t.length()) {
                return 0;
            }
        }
        return t.length() - l;
    }
};