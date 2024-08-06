class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> freq;
        for (auto i : word) {
            freq[i]++;
        }
        priority_queue<int> pq;
        for (auto& i : freq) {
            pq.push(i.second);
        }
        int ct = 0;
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top() * (ct / 8 + 1);
            ct++;
            pq.pop();
        }
        return ans;
    }
};