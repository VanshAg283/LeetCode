class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string> output;
        string first = words[0];
        for (char c : first) {
            mp[c]++;
        }
        for (int i = 1; i < words.size(); ++i) {
            unordered_map<char,int> tmp;
            for (char c : words[i]) {
                tmp[c]++;
            }
            vector<char> toErase;
            for (auto &[chr, count] : mp) {
                if (tmp.find(chr) == tmp.end()) {
                    toErase.push_back(chr);
                } else {
                    mp[chr] = min(count, tmp[chr]);
                }
            }
            for (char c : toErase) {
                mp.erase(c);
            }
        }
        for (auto& [chr, count] : mp) {
            for (int i = 0; i < count; ++i) {
                output.push_back(string(1, chr));
            }
        }
        return output;
    }
};