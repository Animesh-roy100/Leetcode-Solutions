class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0 or k==0) return 0;
        
        if(k >= n/2) {
            int profit=0;
            for(int i=1; i<n; i++) {
                if(prices[i] > prices[i-1]) {
                    profit += prices[i]-prices[i-1]; 
                }
            }
            
            return profit;
        }
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][k];
    }
};