class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle(n);
        for (int i = 0; i < n; ++i) {
            circle[i] = i + 1;
        }
        int start = 0;
        while (circle.size() > 1) {
            start = (start + k - 1) % circle.size(); 
            circle.erase(circle.begin() + start);
        }
        return circle[0];
    }
};