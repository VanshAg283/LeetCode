class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string tmp = "";
        for (int i = 0; i < s.length(); ++i) {
            string str;
            str += s[i];
            if (s[i] == '(') {
                st.push("");
            } else if (s[i] == ')') {
                string s1 = st.top();
                st.pop();
                reverse(s1.begin(), s1.end());
                if (st.empty()) {
                    st.push(s1);
                    continue;
                }
                string s2 = st.top();
                st.pop();
                s2 += s1;
                st.push(s2);
            } else {
                if (st.empty()) {
                    st.push(str);
                    continue;
                }
                string tmp = st.top();
                st.pop();
                tmp.push_back(s[i]);
                st.push(tmp);
            }
        }
        return st.top();
    }
};