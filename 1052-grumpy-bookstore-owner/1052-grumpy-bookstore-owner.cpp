class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                sum += customers[i];
            }
        }
        int w_sum = sum;
        for (int i = minutes; i < customers.size(); ++i) {
            if (grumpy[i - minutes] == 1) {
                w_sum -= customers[i - minutes];
            } if (grumpy[i] == 1) {
                w_sum += customers[i];
            }
            sum = max(sum, w_sum);
        }
        return sum;
    }
};