class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = points[0][i];
        }
        for (int i = 1; i < m; ++i) {
            long long m1 = LLONG_MIN;
            for (int j = 0; j < n; ++j) {
                if (dp[i - 1][j] + j > m1) m1 = dp[i - 1][j] + j;
                dp[i][j] = m1 + points[i][j] - j;
            }
            long long m2 = LLONG_MIN;
            for (int j = n - 1; j >= 0; --j) {
                if (dp[i - 1][j] - j > m2) m2 = dp[i - 1][j] - j;
                dp[i][j] = max(dp[i][j], m2 + points[i][j] + j);
            }
        }
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[m - 1][i]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};