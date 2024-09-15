class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        int ans = 0;
        vector<int> states(32, -1);
        states[0] = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);
            if (states[mask] != -1) {
                ans = max(ans, i + 1 - states[mask]);
            } else {
                states[mask] = i + 1;
            }
        }
        return ans;
    }
};