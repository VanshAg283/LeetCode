class Solution {
public:
    string originalDigits(string s) {
        string ans = "";
        vector<int> ct(10);
        unordered_map<char,int> mp;
        for (char i = 97; i < 123; ++i) {
            mp[i] = 0;
        }
        for (char c : s) {
            mp[c]++;
        }
        ct[0] = mp['z'];
        ct[2] = mp['w'];
        ct[4] = mp['u'];
        ct[6] = mp['x'];
        ct[8] = mp['g'];
        ct[5] = mp['f'] - ct[4];
        ct[3] = mp['h'] - ct[8];
        ct[1] = mp['o'] - ct[0] - ct[2] - ct[4];
        ct[7] = mp['s'] - ct[6];
        ct[9] = mp['i'] - ct[5] - ct[6] - ct[8];
        for (int i = 0; i < 10; ++i) {
            for (int count = 0; count < ct[i]; count++) {
                ans += to_string(i);
            }
        }
        return ans;
    }
};