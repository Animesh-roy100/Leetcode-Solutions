class Solution {
public:
    int solve(int n, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        if(amount==0) return 0;
        if(n == 0) return INT_MAX-1;
        if(dp[n][amount] != -1) return dp[n][amount];

        if(coins[n-1] <= amount) {
            return dp[n][amount] = min(1 + solve(n, coins, amount-coins[n-1], dp), solve(n-1, coins, amount, dp));
        } else {
            return dp[n][amount] = solve(n-1, coins, amount, dp);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = solve(n, coins, amount, dp);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};