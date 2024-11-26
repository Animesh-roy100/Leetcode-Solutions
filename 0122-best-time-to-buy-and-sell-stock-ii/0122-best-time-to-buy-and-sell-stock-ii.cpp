class Solution {
public:
    int solve(int i, vector<int> &prices, int buy, vector<vector<int>> &dp) {
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy) {
            return dp[i][buy] = max(-prices[i] + solve(i+1, prices, 0, dp), solve(i+1, prices, 1, dp));
        } else {
            return dp[i][buy] = max(prices[i] + solve(i+1, prices, 1, dp), solve(i+1, prices, 0, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, prices, 1, dp);
//         int profit=0;
//         int n=prices.size();
//         for(int i=1; i<n; i++) {
//             if(prices[i] > prices[i-1]) {
//                 profit += (prices[i]-prices[i-1]);
//             }
//         }
        
//         return profit;
    }
};