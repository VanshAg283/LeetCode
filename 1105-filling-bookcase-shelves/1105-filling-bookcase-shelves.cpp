class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            int currWidth = 0, maxHeight = 0;
            for (int j = i; j < n && currWidth + books[j][0] <= shelfWidth; ++j) {
                currWidth += books[j][0];
                maxHeight = max(maxHeight, books[j][1]);
                dp[i] = min(dp[i], maxHeight + dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};