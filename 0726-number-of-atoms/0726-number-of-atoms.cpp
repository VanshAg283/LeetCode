class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});
        int n = formula.length();
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                i++;
                if (isdigit(formula[i])) {
                    string num;
                    num += formula[i];
                    while (isdigit(formula[++i])) {
                        num += formula[i];
                    }
                    map<string, int> mp;
                    mp = st.top();
                    st.pop();
                    for (auto& pr : mp) {
                        pr.second *= stoi(num);
                        st.top()[pr.first] += pr.second;
                    }
                } else {
                    map<string, int> mp;
                    mp = st.top();
                    st.pop();
                    for (auto& pr : mp) {
                        st.top()[pr.first] += pr.second;
                    }
                    continue;
                }
            } else {
                if (isupper(formula[i])) {
                    string elt;
                    elt += formula[i];
                    i++;
                    if (islower(formula[i])) {
                        elt += formula[i];
                        i++;
                        if (isdigit(formula[i])) {
                            string num;
                            num += formula[i];
                            while (isdigit(formula[++i])) {
                                num += formula[i];
                            }
                            st.top()[elt] += (1 * stoi(num));
                        } else {
                            st.top()[elt]++;
                            continue;
                        }
                    } else if (isdigit(formula[i])) {
                        string num;
                        num += formula[i];
                        while (isdigit(formula[++i])) {
                            num += formula[i];
                        }
                        st.top()[elt] += (1 * stoi(num));
                    } else {
                        st.top()[elt]++;
                    }
                }
            }
        }
        string ans;
        for (auto& pair : st.top()) {
            cout << pair.first << ":" << pair.second << endl;
            ans += pair.first;
            if (pair.second == 1) {
                continue;
            }
            ans += to_string(pair.second);
        }
        return ans;
    }
};