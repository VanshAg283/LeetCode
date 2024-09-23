class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        set<string> dict;
        for (auto& i : dictionary) {
            dict.insert(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1];   // skipping the character
            for (int len = 1; len <= n - i; ++len) {
                string sub = s.substr(i, len);
                if (dict.find(sub) != dict.end()) {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};