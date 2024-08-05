class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for (auto i : arr) {
            mp[i]++;
        }
        vector<string> unique;
        for (auto i : arr) {
            if (mp[i] == 1) {
                unique.push_back(i);
            }
        }
        for (auto i : unique) {
            cout << i << endl;
        }
        if (unique.size() < k) return "";
        return unique[k - 1];
    }
};