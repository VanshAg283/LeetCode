class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int m = values[0];
        int ans = 0;
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, m + values[i] - i);
            if (values[i] + i > m) m = values[i] + i;
        }
        return ans;
    }
};