class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans(rows * cols, vector<int>(2));
        int rct = 1, cct = 1;
        int ct = 1;
        ans[0][0] = rStart;
        ans[0][1] = cStart;
        while (ct < rows * cols) {
            for (int i = 0; i < cct; ++i) {
                cStart++;
                if (cStart >= 0 && rStart >=0 && cStart < cols && rStart < rows) {
                    ans[ct][0] = rStart;
                    ans[ct][1] = cStart;
                    ct++;
                }
            }
            cct++;
            for (int i = 0; i < rct; ++i) {
                rStart++;
                if (cStart >= 0 && rStart >=0 && cStart < cols && rStart < rows) {
                    ans[ct][0] = rStart;
                    ans[ct][1] = cStart;
                    ct++;
                }
            }
            rct++;
            for (int i = 0; i < cct; ++i) {
                cStart--;
                if (cStart >= 0 && rStart >=0 && cStart < cols && rStart < rows) {
                    ans[ct][0] = rStart; 
                    ans[ct][1] = cStart;
                    ct++;
                }
            }
            cct++;
            for (int i = 0; i < rct; ++i) {
                rStart--;
                if (cStart >= 0 && rStart >=0 && cStart < cols && rStart < rows) {
                    ans[ct][0] = rStart;
                    ans[ct][1] = cStart;
                    ct++;
                }
            }
            rct++;
        }
        return ans;
    }
};