class Solution {
public:
    int getLucky(string s, int k) {
        string new_s;
        for (int i = 0; i < s.length(); ++i) {
            int t = s[i] - 'a' + 1;
            new_s += to_string(t);
        }
        int i = 0;
        while (i < k) {
            int su = 0;
            for (int i = 0; i < new_s.length(); ++i) {
                string tmp;
                tmp += new_s[i];
                su += stoi(tmp);
            }
            new_s = to_string(su);
            i++;
        }
        return stoi(new_s);
    }
};