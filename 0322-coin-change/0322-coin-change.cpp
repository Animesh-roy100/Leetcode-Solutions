class Solution {
public:
//     int solve(int n, int amt, vector<int> &coins, vector<vector<int>> &dp) {
//         if(amt == 0) return 0;
//         if(n == 0) return INT_MAX-1;
//         if(dp[n][amt] != -1) return dp[n][amt];
        
//         if(coins[n-1] <= amt) {
//             return dp[n][amt] = min(1 + solve(n, amt-coins[n-1], coins, dp), solve(n-1, amt, coins, dp));
//         } else {
//             return dp[n][amt] = solve(n-1, amt, coins, dp);
//         }
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        // int ans = solve(n, amount, coins, dp);
        // return ans == INT_MAX-1 ? -1 : ans;
        
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=0; i<n; i++) {
            for(int j=coins[i]; j<=amount ; j++) {
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};