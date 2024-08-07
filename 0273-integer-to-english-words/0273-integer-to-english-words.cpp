class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        unordered_map<int, string> d = {{0, "Zero"},
                                        {1, "One"},
                                        {2, "Two"},
                                        {3, "Three"},
                                        {4, "Four"},
                                        {5, "Five"},
                                        {6, "Six"},
                                        {7, "Seven"},
                                        {8, "Eight"},
                                        {9, "Nine"},
                                        {10, "Ten"},
                                        {11, "Eleven"},
                                        {12, "Twelve"},
                                        {13, "Thirteen"},
                                        {14, "Fourteen"},
                                        {15, "Fifteen"},
                                        {16, "Sixteen"},
                                        {17, "Seventeen"},
                                        {18, "Eighteen"},
                                        {19, "Nineteen"},
                                        {20, "Twenty"},
                                        {30, "Thirty"},
                                        {40, "Forty"},
                                        {50, "Fifty"},
                                        {60, "Sixty"},
                                        {70, "Seventy"},
                                        {80, "Eighty"},
                                        {90, "Ninety"},
                                        {100, "One Hundred"},
                                        {1000, "One Thousand"},
                                        {1000000, "One Million"},
                                        {1000000000, "One Billion"}};
        if (d.find(num) != d.end())
            return d[num];
        vector<string> words;
        int tmp = num;
        while (tmp > 0) {
            int dig = tmp % 1000;
            tmp = tmp / 1000;
            if (d.find(dig) != d.end()) {
                words.push_back(d[dig]);
                continue;
            }
            int ones = dig % 10;
            int tens = (dig % 100 - ones);
            int hundred = (dig - (dig % 100)) / 100;
            string s = "";
            if (hundred != 0) {
                if (tens + ones == 0) {
                    s += d[hundred] + " Hundred";
                    words.push_back(s);
                    continue;
                }
                s = s + d[hundred] + " Hundred ";
            }
            if (tens != 0 && tens != 10) {
                if (ones == 0) {
                    s += d[tens];
                    words.push_back(s);
                    continue;
                }
                s += d[tens] + " ";
            }
            if (tens == 10) {
                s += d[tens + ones];
                words.push_back(s);
                continue;
            }
            if (ones != 0) {
                s += d[ones];
            }
            words.push_back(s);
        }
        string ans = "";
        int ct = 0;
        for (auto i : words) {
            if (i == "Zero") {
                ct++;
                continue;
            }
            if (ct == 0) ans = i + ans;
            else if (ct == 1) {
                if (ans == "") ans = i + " Thousand";
                else ans = i + " Thousand " + ans;
            } 
            else if (ct == 2) {
                if (ans == "") ans = i + " Million";
                else ans = i + " Million " + ans;
            } 
            else if (ct == 3){ 
                if (ans == "") ans = i + " Billion";
                else ans = i + " Billion " + ans;
            }  
            ct++;
        }
        return ans;
    }
};