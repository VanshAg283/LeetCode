class Solution {
private:
    double dijkstra(int src, int dest, vector<vector<pair<int, double>>>& adj,
                    int n) {
        vector<double> prob(n, 0.0);
        prob[src] = 1.0;
        priority_queue<pair<double, int>> pq;

        pq.push({1.0, src});
        while (!pq.empty()) {
            double p = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for (auto it : adj[curr]) {
                int next = it.first;
                double next_p = it.second;
                if (prob[next] < p * next_p) {
                    prob[next] = p * next_p;
                    pq.push({prob[next], next});
                }
            }
        }

        return prob[dest];
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        double ans = dijkstra(start_node, end_node, adj, n);
        return ans;
    }
};