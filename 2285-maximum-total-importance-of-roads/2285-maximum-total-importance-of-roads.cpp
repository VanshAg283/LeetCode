class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); ++i) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(adj[i].size(),i));
        }
        int curr = n;
        vector<int> val(n);
        while (!pq.empty()) {
            val[pq.top().second] = curr;
            curr--;
            pq.pop();

        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
           ans += (val[i] * adj[i].size());
        }
        return ans;
    }
};