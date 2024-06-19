class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0;
        int b = 0;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day) count++;
            else
            {
                b += (count / k);
                count = 0;
            }
        }
        b += (count / k);
        if(b >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // long long req = m * k;
        // if (req > n) {
        //     return -1;
        // }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        return ans;
    }
};