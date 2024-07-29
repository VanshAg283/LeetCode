class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        for (int j = 1; j < n - 1; ++j) {
            int less_left = 0, greater_left = 0;
            int less_right = 0, greater_right = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j])
                    less_left++;
                if (rating[i] > rating[j])
                    greater_left++;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j])
                    less_right++;
                if (rating[k] > rating[j])
                    greater_right++;
            }
            teams += less_left * greater_right + greater_left * less_right;
        }

        return teams;
    }
};