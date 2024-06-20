class Solution {
public:
    bool check(vector<int>& position, int m, int mid) {
        int curr = position[0];
        int b = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (abs(position[i] - curr) >= mid) {
                b++;
                curr = position[i];
            }
        }
        if (b >= m) {
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int high = position[n - 1] - position[0];
        int low = 1;      
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};