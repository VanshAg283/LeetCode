class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        set<char> vowels(v.begin(), v.end());
        vector<int> preSum(words.size() + 1, 0);
        for (int i = 1; i <= words.size(); ++i) {
            string curr = words[i - 1];
            int l = curr.length();
            if (vowels.find(curr[0]) != vowels.end() &&
                vowels.find(curr[l - 1]) != vowels.end()) {
                    preSum[i] = preSum[i - 1] + 1;
                }
            else {
                preSum[i] = preSum[i - 1];
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = preSum[queries[i][1] + 1] - preSum[queries[i][0]];
        }
        return ans;
    }
};