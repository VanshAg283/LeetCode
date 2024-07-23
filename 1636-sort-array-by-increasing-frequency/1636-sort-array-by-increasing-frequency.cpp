class Solution {
private:
    static bool comparison(pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> n;
        for (auto i : mp) {
            n.push_back(make_pair(i.second, i.first));
        }
        sort(n.begin(), n.end(), comparison);
        vector<int> ans;
        for (auto pr : n) {
            int freq = pr.first;
            int num = pr.second;
            while (freq--) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};