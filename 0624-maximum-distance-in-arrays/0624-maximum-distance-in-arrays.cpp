class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        int idx;
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < mi) {
                mi = arrays[i][0];
                idx = i;
            }
        }
        for (int i = 0; i < arrays.size(); ++i) {
            int n = arrays[i].size() - 1;
            if (arrays[i][n] > ma && i != idx) {
                ma = arrays[i][n];
            }
        }
        cout << ma << mi;
        int ans = ma - mi;
        ma = INT_MIN;
        mi = INT_MAX;
        int idx2;
        for (int i = 0; i < arrays.size(); ++i) {
            int n = arrays[i].size() - 1;
            if (arrays[i][n] > ma) {
                ma = arrays[i][n];
                idx2 = i;
            }
        }
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < mi && i != idx2) {
                mi = arrays[i][0];
            }
        }
        cout << '\n';
        cout << ma << mi;
        ans = max(ans, ma - mi);
        return ans;
    }
};