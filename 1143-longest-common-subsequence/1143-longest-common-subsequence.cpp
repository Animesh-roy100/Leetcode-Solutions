class Solution {
public:
    int solve(string t1, string t2, int i, int j, vector<vector<int>> &dp) {
        if(i==0 or j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i-1] == t2[j-1]){
            return dp[i][j] = 1 + solve(t1, t2, i-1, j-1, dp);
        } else {
            return dp[i][j] = max(solve(t1, t2, i-1, j, dp), solve(t1, t2, i, j-1, dp));
        }
    }
        
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.length(), m=t2.length();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return solve(t1, t2, n, m, dp);
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};