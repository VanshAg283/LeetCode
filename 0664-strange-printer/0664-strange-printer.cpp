class Solution {
public:
    int strangePrinter(string s) {
        string mod;
        mod += s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1])
                mod += s[i];
        }

        int n = mod.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k <= j; ++k) {
                    if (mod[i] == mod[k]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};