class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> graph(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < 26; ++i) {
            graph[i][i] = 0;
        }
        for (int i = 0; i < original.size(); ++i) {
            long long w = (long long)cost[i];
            graph[original[i] - 'a'][changed[i] - 'a'] = min(w, graph[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX)
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (graph[i][j] == LLONG_MAX) {
                    cout << "M" << " ";
                }
                else cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        long long ans = 0;
        for (int i = 0; i < source.length(); ++i) {
            if (graph[source[i] - 'a'][target[i]- 'a'] == LLONG_MAX) return -1;
            ans += graph[source[i] - 'a'][target[i]- 'a'];
        }
        return ans;
    }
};