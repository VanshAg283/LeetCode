class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins(timePoints.size());
        for (int i = 0; i < timePoints.size(); ++i) {
            string s = timePoints[i];
            string h = s.substr(0,2);
            string m = s.substr(3,2);
            int hours = stoi(h);
            int minutes = stoi(m);
            mins[i] = 60 * hours + minutes;
            cout << mins[i] << " ";
        }
        sort(mins.begin(), mins.end());
        int ans = INT_MAX;
        for (int i = 0; i < mins.size() - 1; ++i) {
            int a1 = abs(mins[i + 1] - mins[i]);
            int a2 = abs(1440 + mins[i] - mins[i + 1]);
            int min_a = min(a1, a2);
            ans = min(ans, min_a);
        }
        int a1 = abs(mins[mins.size() - 1] - mins[0]);
        int a2 = abs(1440 + mins[0] - mins[mins.size() - 1]);
        int min_a = min(a1, a2);
        ans = min(ans, min_a);
        return ans;
    }
};