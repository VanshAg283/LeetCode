class Solution {
public:
    int countPalindromes(string s) {
        long long ans = 0;
        const int MOD = 1000000007;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string pattern = to_string(x) + to_string(y) + "|" +
                                 to_string(y) + to_string(x);
                vector<long long> dp(6, 0);
                dp[5] = 1;
                for (char c : s) {
                    for (int j = 0; j < 5; ++j) {
                        if (c == pattern[j] || j == 2) {
                            dp[j] = (dp[j] + dp[j + 1]) % MOD;
                        }
                    }
                }
                ans = (ans + dp[0]) % MOD;
            }
        }
        return ans;
    }
};