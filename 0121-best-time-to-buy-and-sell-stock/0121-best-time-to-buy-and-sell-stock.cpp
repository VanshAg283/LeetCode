class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int m = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < m) {
                m = prices[i];
            } else {
                p = max(p, prices[i] - m);
            }
        }
        return p;
    }
};