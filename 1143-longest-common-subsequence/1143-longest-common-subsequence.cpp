class Solution {
public:
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n==0 or m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n-1] == s2[m-1]) {
            return dp[n][m] = 1 + solve(n-1, m-1, s1, s2, dp);
        } else {
            return dp[n][m] = max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, s1, s2, dp);
    }
};