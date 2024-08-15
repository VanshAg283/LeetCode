class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for (auto& i : bills) {
            if (i == 5) fives++;
            else if (i == 10) {
                tens++;
                if (fives <= 0) return false;
                else fives--;
            } else {
                if (tens <= 0) {
                    if (fives <= 2) return false;
                    else fives -= 3;
                } else {
                    if (fives <= 0) return false;
                    else {
                        tens--;
                        fives--;
                    }
                }
            }
        }
        return true;
    }
};