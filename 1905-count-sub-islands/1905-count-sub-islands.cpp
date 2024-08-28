class Solution {
public:
    void dfs(int m, int n, vector<vector<int>>& grid1,
            vector<vector<int>>& grid2, int row, int col, bool &check) {
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        grid2[row][col] = 0;
        for (int i = 0; i < 4; ++i) {
            int crow = row + x[i];
            int ccol = col + y[i];
            if (crow >= 0 && ccol >= 0 && ccol < n && crow < m) {
                if (grid2[crow][ccol] == 1 && grid1[crow][ccol] == 1) {
                    cout << "row: " << crow << " " << "col: " << ccol << endl;
                    dfs(m, n, grid1, grid2, crow, ccol, check);
                } else if (grid2[crow][ccol] == 1 && grid1[crow][ccol] == 0) {
                    check = false;
                    dfs(m, n, grid1, grid2, crow, ccol, check);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ct = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                    bool check = true;
                    dfs(m, n, grid1, grid2, i, j, check);
                    if (check) {
                        cout << i << " " << j << endl;
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};