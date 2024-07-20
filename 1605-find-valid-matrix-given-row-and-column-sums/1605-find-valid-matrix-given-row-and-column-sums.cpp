class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> row;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> col;
        for (int i = 0; i < rowSum.size(); ++i) {
            row.push(make_pair(rowSum[i], i));
        }
        for (int i = 0; i < colSum.size(); ++i) {
            col.push(make_pair(colSum[i], i));
        }
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), -1));
        while (!row.empty() && !col.empty()) {
            pair<int,int> lrow = row.top();
            pair<int,int> lcol = col.top();
            row.pop();
            col.pop();
            if (lrow.first <= lcol.first) {
                ans[lrow.second][lcol.second] = lrow.first;
                col.push(make_pair(lcol.first - lrow.first, lcol.second));
                for (int i = 0; i < colSum.size(); ++i) {
                    if (i != lcol.second && ans[lrow.second][i] == -1) {
                        ans[lrow.second][i] = 0;
                    }
                }
            } else {
                ans[lrow.second][lcol.second] = lcol.first;
                row.push(make_pair(lrow.first - lcol.first, lrow.second));
                for (int i = 0; i < rowSum.size(); ++i) {
                    if (i != lrow.second && ans[i][lcol.second] == -1) {
                        ans[i][lcol.second] = 0;
                    }
                }
            }
        }
        return ans;
    }
};