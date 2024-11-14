class Solution {
public:
    int solve(vector<int> &coins, int i, int amt, vector<vector<int>> &dp) {
        if(amt==0) return 1;
        if(i==0) return 0;
        
        if(dp[i][amt] != -1) return dp[i][amt];
        
        if(coins[i-1] <= amt) {
            return dp[i][amt] = solve(coins, i, amt-coins[i-1], dp) + solve(coins, i-1, amt, dp);
        } else {
            return dp[i][amt] = solve(coins, i-1, amt, dp);
        }
    }
    
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amt+1, -1));
        
        return solve(coins, n, amt, dp);
    }
};