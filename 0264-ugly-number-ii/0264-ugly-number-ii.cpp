class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int l1 = 0, l2 = 0, l3 = 0;
        int next2 = dp[l1] * 2;
        int next3 = dp[l2] * 3;
        int next5 = dp[l3] * 5;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(next2, min(next3, next5));
            if (dp[i] == next2) l1++;
            if (dp[i] == next3) l2++;
            if (dp[i] == next5) l3++;
            next2 = dp[l1] * 2;
            next3 = dp[l2] * 3;
            next5 = dp[l3] * 5;
        }
        return dp[n - 1];
    }
};