class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currTime = customers[0][0] + customers[0][1];
        long long waitTime = currTime - customers[0][0];
        for (int i = 1; i < customers.size(); ++i) {
            if (currTime >= customers[i][0]) {
                currTime += customers[i][1];
            } else {
                currTime = customers[i][0] + customers[i][1];
            }
            waitTime += currTime - customers[i][0];
        }
        double ans = (double)waitTime/(double)customers.size();
        return ans;
    }
};