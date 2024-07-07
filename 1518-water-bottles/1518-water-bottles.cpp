class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ct = 0;
        int bl = 0;
        int prevbl = 0;
        while (numBottles > 0) {
            ct += numBottles;
            bl = (numBottles + prevbl) % numExchange;
            numBottles = (numBottles + prevbl)/numExchange;
            prevbl = bl;
        }
        return ct;
    }
};