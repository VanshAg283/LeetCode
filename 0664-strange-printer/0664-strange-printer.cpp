class Solution {
public:
    int helper(string s, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int num = 1 + helper(s, start + 1, end, dp);
        for (int i = start + 1; i <= end; ++i) {
            if (s[start] == s[i]) {
                num = min(num, helper(s, start, i - 1, dp) + helper(s, i + 1, end, dp));
            }
        }
        return dp[start][end] = num;
    }
    int strangePrinter(string s) {
        string mod;
        mod += s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1])
                mod += s[i];
        }
        int n = mod.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(mod, 0, n - 1, dp);
    }
};