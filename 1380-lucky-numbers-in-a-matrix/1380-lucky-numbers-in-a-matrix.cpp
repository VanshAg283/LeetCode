class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<pair<int,int>> rows;
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) {
            int min_elt = 100001;
            int row = i;
            int col = 0;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < min_elt) {
                    min_elt = matrix[i][j];
                    row = i;
                    col = j;
                }
            }
            rows.insert(make_pair(row, col));
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            int max_elt = 0;
            int row = 0;
            int col = i;
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[j][i] > max_elt) {
                    max_elt = matrix[j][i];
                    row = j;
                    col = i;
                }
            }
            if (rows.find(make_pair(row,col)) != rows.end()) {
                ans.push_back(matrix[row][col]);
            }
        }
        return ans;
    }
};