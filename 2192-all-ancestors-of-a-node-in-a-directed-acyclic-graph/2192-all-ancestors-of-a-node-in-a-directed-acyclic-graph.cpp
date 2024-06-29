class Solution {
private:
    void bfs(int node, vector<vector<int>>& adj, vector<vector<int>>& ans) {
        queue<int> q;
        q.push(node);
        vector<int> visited(adj.size(), 0);
        visited[node] = 1;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int i : adj[n]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                    ans[node].push_back(i);
                }
            }
        }
        sort(ans[node].begin(), ans[node].end());
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> ancestors(n);
        for (int i = 0; i < n; ++i) {
            bfs(i, adj, ancestors);
        }
        return ancestors;
    }
};