class Solution {
public:
    int minLength(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && 
               ((stack.back() == 'A' && c == 'B') || 
                (stack.back() == 'C' && c == 'D'))) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.size();
    }
};