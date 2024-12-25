class Solution {
public:
    int solve(int n, int amt, vector<int> &coins, vector<vector<int>> &dp) {
        if(amt == 0) return 0;
        if(n == 0) return INT_MAX-1;
        if(dp[n][amt] != -1) return dp[n][amt];
        
        if(coins[n-1] <= amt) {
            return dp[n][amt] = min(1 + solve(n, amt-coins[n-1], coins, dp), solve(n-1, amt, coins, dp));
        } else {
            return dp[n][amt] = solve(n-1, amt, coins, dp);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = solve(n, amount, coins, dp);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};