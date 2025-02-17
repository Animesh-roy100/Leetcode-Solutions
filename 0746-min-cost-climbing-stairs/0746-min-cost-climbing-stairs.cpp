class Solution {
public:
//     int solve(int i, vector<int> &cost, vector<int> &dp) {
//         if(i<=1) return dp[i] = cost[i];
//         if(dp[i] != -1) return dp[i];
        
//         return dp[i] = cost[i] + min(solve(i-1, cost, dp), solve(i-2, cost, dp));
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int> dp(n, -1);
        // return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
        
        int prev1 = cost[1];
        int prev2 = cost[0];
        
        for(int i=2; i<n; i++) {
            int current = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        return min(prev1, prev2);
    }
};