class Solution {
public:
    void find(vector<int>& candidates, int target, int idx,
              vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        int prev = -1;
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (prev == candidates[i]) continue;
            curr.push_back(candidates[i]);
            find(candidates, target - candidates[i], i + 1, ans, curr);
            curr.pop_back();
            prev = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        find(candidates, target, 0, ans, curr);
        return ans;
    }
};