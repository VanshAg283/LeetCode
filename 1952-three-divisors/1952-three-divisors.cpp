class Solution {
public:
    bool isThree(int n) {
        int ct = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                ct += i * i == n ? 1 : 2;
            } 
        }
        if (ct == 3) {
            return true;
        }
        return false;
    }
};