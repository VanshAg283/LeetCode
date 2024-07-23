class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long b = n;
        if (n < 0) {
            x = 1/x;
            b = -(long)n;
        }
        while (b > 0) {
            if (b & 1) {
                res = res * x;
            }
            x = x * x;
            b>>=1;
        }
        return res;
    }
};