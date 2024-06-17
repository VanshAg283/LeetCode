class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c);
        while (low <= high) {
            long long sum = low * low + high * high;
            if (sum < c) {
                low++;
            } else if (sum > c) {
                high--;
            } else {
                return true;
            }
        }
        return false;
    }
};