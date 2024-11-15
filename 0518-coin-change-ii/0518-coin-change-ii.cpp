class Solution {
public:
    #define ui unsigned int
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<ui>> dp(n+1, vector<ui> (amt+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=amt; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amt];
    }
};