class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            pre[i + 1] = pre[i] ^ arr[i];
        }
        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(pre[q[1] + 1] ^ pre[q[0]]);
        }
        return ans;
    }
};