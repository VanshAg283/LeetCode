class Solution {
private:
    int dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n, int distThreshold) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            int curr = pq.top().second;
            int curr_d = pq.top().first;
            pq.pop();
            for (auto it : adj[curr]) {
                int next = it.first;
                int next_d = it.second;
                if (dist[next] > curr_d + next_d) {
                    dist[next] = curr_d + next_d;
                    pq.push({dist[next], next});
                }
            }
        }
        int neighbours = 0;
        for (int i = 0; i < n; ++i) {
            if (i != src) {
                if (dist[i] <= distThreshold) {
                    neighbours++;
                } 
            }
        }
        return neighbours;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
            adj[i[1]].push_back(make_pair(i[0], i[2]));
        }
        int min_nb = INT_MAX;
        int city;
        for (int i = 0; i < n; ++i) {
            int nb = dijkstra(i, adj, n, distanceThreshold);
            if (nb <= min_nb) {
                min_nb = nb;
                city = i;
            }
        }
        return city;
    }
};