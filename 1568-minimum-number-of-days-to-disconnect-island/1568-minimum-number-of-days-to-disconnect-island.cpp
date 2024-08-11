class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        grid[row][col] = 0;
        int x[4] = {0, -1, 0, 1};
        int y[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; ++i) {
            int crow = row + x[i];
            int ccol = col + y[i];
            if (crow < m && crow >= 0 && ccol < n && ccol >= 0 && grid[crow][ccol] == 1) {
                dfs(grid, crow, ccol);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<int>> tempGrid = grid;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (tempGrid[i][j] == 1) {
                    dfs(tempGrid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int islands = countIslands(grid);
        if (islands > 1 || islands == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    if (countIslands(grid) > 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};