class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> mp;
        string word;
        for (int i = 0 ; i < s1.length(); ++i) {
            if (s1[i] == ' ') {
                mp[word]++;
                word = "";
                continue;
            }
            word += s1[i];
        }
        mp[word]++;
        string word2;
        for (int i = 0 ; i < s2.length(); ++i) {
            if (s2[i] == ' ') {
                mp[word2]++;
                word2 = "";
                continue;
            }
            word2 += s2[i];
        }
        mp[word2]++;
        for (auto& i : mp) {
            cout << i.first << ":" << i.second << endl;
            if (i.second == 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};