class Solution {
public:
//     int solve(vector<int> &coins, int i, int amt, vector<vector<int>> &dp) {
//         if(amt == 0) return 0;
//         if(i==0) return INT_MAX-1;
//         if(dp[i][amt] != -1) return dp[i][amt];
        
//         if(coins[i-1] <= amt) {
//             return dp[i][amt] = min(1 + solve(coins, i, amt - coins[i-1], dp), solve(coins, i-1, amt, dp));
//         } else {
//             return dp[i][amt] = solve(coins, i-1, amt, dp);
//         }
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        // int res = solve(coins, n, amount, dp);
        // return res == INT_MAX-1 ? -1 : res;
        
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        
        for(int j=1; j<=amount; j++) dp[0][j] = INT_MAX-1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};