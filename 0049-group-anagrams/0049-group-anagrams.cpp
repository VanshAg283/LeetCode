class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ct;
        for (auto s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            ct[tmp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto i : ct) {
            vector<string> tmp;
            for (string str : i.second) {
                tmp.push_back(str);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};