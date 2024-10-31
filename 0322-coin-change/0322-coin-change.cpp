class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        
        int minCoins = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int res = solve(coins, amount-coins[i], dp);
            if(res != INT_MAX) {
                minCoins = min(minCoins, res+1);
            }
        }
        
        dp[amount] = minCoins;
        
        return minCoins;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int> dp(amount+1, -1);
        int res = solve(coins, amount, dp);
        if(res == INT_MAX) return -1;
        return res;
    }
};