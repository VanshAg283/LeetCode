class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        if (s1.length() > s2.length()) return false;
        for (int i = 0; i < s1.length(); ++i) {
            freq1[s1[i]- 'a']++;
        }
        for (int i = 0; i < s1.length(); ++i) {
            freq2[s2[i] - 'a']++;
        }
        auto arraysEqual = [](int a[], int b[]) {
            for (int i = 0; i < 26; ++i) {
                if (a[i] != b[i]) return false;
            }
            return true;
        };
        if (arraysEqual(freq1, freq2)) return true;
        for (int i = s1.length(); i < s2.length(); ++i) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - s1.length()] - 'a']--;
            if (arraysEqual(freq1, freq2)) return true;
        }
        return false;
    }
};