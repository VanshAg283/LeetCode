class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> count(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || ++count[num] > 1) {
                    return false;
                }
            }
        }

        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; ++i) {
            if (grid[row + i][col] + grid[row + i][col + 1] +
                    grid[row + i][col + 2] !=
                sum) {
                return false;
            }
            if (grid[row][col + i] + grid[row + 1][col + i] +
                    grid[row + 2][col + i] !=
                sum) {
                return false;
            }
        }

        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] !=
                sum ||
            grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] !=
                sum) {
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (rows < 3 || cols < 3)
            return 0;
        int ans = 0;
        bool flag = true;
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};