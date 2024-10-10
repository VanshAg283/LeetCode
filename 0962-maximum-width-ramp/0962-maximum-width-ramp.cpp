class Solution {
public:
    vector<int> monotonicDecreasing(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; 
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        while (!st.empty()) {
            result.insert(result.begin(), st.top());
            st.pop();
        }

        return result;
    }

    int maxWidthRamp(vector<int>& nums) {
        vector<int> st = monotonicDecreasing(nums); 
        int res = 0;
        int n = nums.size();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= nums[st.back()]) {
                res = max(res, i - st.back());
                st.pop_back(); 
            }
        }

        return res;
    }
};