class Solution {
private:
    vector<int> dijkstra(int src, vector<vector<int>>& graph, int n) {
        vector<int> dist(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            int curr = pq.top().second;
            int curr_d = pq.top().first;
            pq.pop();
            for (auto it : graph[curr]) {
                int next = it;
                int next_d = 1;
                if (dist[next] > curr_d + next_d) {
                    dist2[next] = dist[next];
                    dist[next] = curr_d + next_d;
                    pq.push({dist[next], next});
                } else if (curr_d + next_d > dist[next] &&
                           curr_d + next_d < dist2[next]) {
                    dist2[next] = curr_d + next_d;
                    pq.push({dist2[next], next});
                }
            }
        }
        return dist2;
    }

public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> secMin = dijkstra(1, graph, n);
        for (int i = 1; i < secMin.size(); ++i) {
            cout << secMin[i] << " ";
        }
        cout << endl;
        int ans = 0;
        int paths = secMin[n];
        for (int i = 0; i < paths; ++i) {
            if ((ans/change) % 2) {
                ans = (ans/change + 1) * change; 
            }
            ans += time;
        }
        return ans;
    }
};