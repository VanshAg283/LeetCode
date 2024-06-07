class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());
        set<string> dict;
        for (auto&d : dictionary) {
            dict.insert(d);
        }
        vector<string> words;
        int flag = 0;
        string word = "";
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                if (flag == 0) words.push_back(word);
                word = "";
                flag = 0;
            } else {
                word = word + sentence[i];
                if (dict.find(word) != dict.end() && flag == 0) {
                    words.push_back(word);
                    flag = 1;
                    word = "";
                }
            }
            if (i == sentence.size() - 1 && word != "" && flag == 0) {
                words.push_back(word);
            }
        }
        string ans = "";
        for (int i = 0; i < words.size(); ++i) {
            if (i != words.size() - 1) {
                ans = ans + words[i] + " ";
            }
            else {
                ans = ans + words[i];
            }
        }
        return ans;
    }
};