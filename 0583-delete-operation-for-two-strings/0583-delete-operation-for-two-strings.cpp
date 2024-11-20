class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.length(), m=w2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(w1[i-1] == w2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return m+n-2*dp[n][m];
    }
};