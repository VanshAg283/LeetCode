class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> hn;
        for (int i = 0; i < names.size(); ++i) {
            hn.push_back(make_pair(heights[i], names[i]));
        }
        sort(hn.rbegin(), hn.rend());
        vector<string> ans;
        for (auto p : hn) {
            ans.push_back(p.second);
        }
        return ans;
    }
};