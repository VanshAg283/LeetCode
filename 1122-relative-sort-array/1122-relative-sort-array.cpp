class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for (int i = 0; i < arr1.size(); ++i) {
            m[arr1[i]]++;
        }
        vector<int> sorted;
        for (int i = 0; i < arr2.size(); ++i) {
            int ct = m[arr2[i]];
            for (int j = 0; j < ct; ++j) {
                sorted.push_back(arr2[i]);
            }
            m.erase(arr2[i]);
        }
        for (auto& i : m) {
            int ct = i.second;
            for (int j = 0; j < ct; ++j) {
                sorted.push_back(i.first);
            }
        }
        return sorted;
    }
};