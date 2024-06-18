class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> dp;
        dp.push_back(make_pair(0, 0));
        for (int i = 0; i < n; ++i) {
            dp.push_back(make_pair(difficulty[i], profit[i]));
        }
        int pr = 0;
        int start = 0;
        sort(dp.begin(), dp.end());
        sort(worker.begin(), worker.end());
        for (int i = 0; i < worker.size(); ++i) {
            while (start < n + 1) {
                if (worker[i] >= dp[start].first) {
                    start++;
                } else {
                    start--;
                    break;
                }
            }
            if (start == n + 1) {
                pr += dp[n].second;
                start--;
                continue;
            }
            pr += dp[start].second;
        }
        return pr;
    }
};