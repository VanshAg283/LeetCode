class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n));
        if (original.size() != m * n) return {};
        int row = 0;
        int col = 0;
        for (int i = 0; i < original.size(); ++i) {
            if (col < n) {
                ans[row][col] = original[i];
                col++;
            }
            if (col == n) {
                row++;
                col = 0;
            }
        }
        return ans;
    }
};