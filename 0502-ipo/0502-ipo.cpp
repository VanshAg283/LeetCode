class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for (int i = 0; i < capital.size(); ++i) {
            v.emplace_back(capital[i], profits[i]);
        }
        sort(v.begin(), v.end());
        int id = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            while (id < capital.size() && v[id].first <= w) {
                pq.push(v[id].second);
                id++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};