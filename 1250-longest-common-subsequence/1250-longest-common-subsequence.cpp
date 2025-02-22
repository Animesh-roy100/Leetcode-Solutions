class Solution {
public:

    // int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
    //     if(i>=s1.length() or j>=s2.length()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]) {
    //         return dp[i][j] = 1 + solve(i+1, j+1, s1, s2, dp);
    //     } else {
    //         return dp[i][j] = max(solve(i+1, j, s1, s2, dp), solve(i, j+1, s1, s2, dp));
    //     }
    // }

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(), m=s2.size();

        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return solve(0, 0, s1, s2, dp); 

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};