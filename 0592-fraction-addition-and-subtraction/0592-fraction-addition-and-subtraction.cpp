class Solution {
public:
    string fractionAddition(string s) {
        vector<int> num;
        vector<int> den;
        int idx;
        if (s[0] == '-') {
            string tmp;
            tmp += s[1];
            int n = stoi(tmp);
            num.push_back(-n);
            idx = 2;
        } else {
            string tmp;
            tmp += s[0];
            int n = stoi(tmp);
            num.push_back(n);
            idx = 1;
        }
        for (int i = idx; i < s.length(); ++i) {
            if (s[i] == '/') {
                ++i;
                string tmp;
                tmp += s[i];
                int id = i;
                if (s[id + 1] == '0') {
                    ++i;
                    tmp += s[i];
                }
                den.push_back(stoi(tmp));
            } else if (s[i] == '+') {
                ++i;
                string tmp;
                tmp += s[i];
                int id = i;
                if (s[id + 1] == '0') {
                    ++i;
                    tmp += s[i];
                }
                num.push_back(stoi(tmp));
            } else if (s[i] == '-') {
                ++i;
                string tmp;
                tmp += s[i];
                int id = i;
                if (s[id + 1] == '0') {
                    ++i;
                    tmp += s[i];
                }
                int n = stoi(tmp);
                num.push_back(-n);
            }
        }
        int lcm = den[0];
        for (int i = 1; i < den.size(); ++i) {
            lcm = (lcm * den[i]) / (__gcd(lcm, den[i]));
        }
        int su = 0;
        for (int i = 0; i < num.size(); ++i) {
            int req = lcm / den[i];
            su += num[i] * req;
            cout << su << endl;
        }
        cout << su << '/' << lcm << endl;
        if (su == 0) {
            return "0/1";
        }
        else if (su > 0) {
            int gc = (__gcd(su, lcm));
            cout << gc << endl;
            su = su / gc;
            lcm = lcm / gc;
            string ans = to_string(su) + '/' + to_string(lcm);
            return ans;
        }
        else {
            int gc = (__gcd(-su, lcm));
            cout << gc << endl;
            su = su / gc;
            lcm = lcm / gc;
            string ans = to_string(su) + '/' + to_string(lcm);
            return ans;
        }
    }
};