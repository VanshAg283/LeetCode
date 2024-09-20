class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = string(s.rbegin(), s.rend());
        string concat = s + '#' + rev;
        int n = concat.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && concat[i] != concat[j])
                j = pi[j-1];
            if (concat[i] == concat[j])
                j++;
            pi[i] = j;
        }
        int match = pi[n - 1];
        string ans;
        for (int i = 0; i < rev.length() - match; ++i) {
            ans += rev[i];
        }
        ans += s;
        return ans;
    }
};