class Solution {
public:
//     int solve(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
//         if(i==prices.size()) return 0;
//         if(cap == 0) return 0;
//         if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        
//         if(buy) {
//             return dp[i][buy][cap] = max(-prices[i] + solve(i+1, 0, cap, prices, dp), solve(i+1, 1, cap, prices, dp));
//         } else {
//             return dp[i][buy][cap] = max(prices[i] + solve(i+1, 1, cap-1, prices, dp), solve(i+1, 0, cap, prices, dp));
//         }
//     }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        // return solve(0, 1, 2, prices, dp);
        
        // tabulation
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<2; buy++) {
                for(int cap=1; cap<3; cap++) {
                    if(buy) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
                                              
        return dp[0][1][2];
    }
};