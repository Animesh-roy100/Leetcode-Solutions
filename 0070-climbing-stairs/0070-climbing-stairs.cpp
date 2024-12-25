class Solution {
public:
//     int solve(int n, vector<int> &dp) {
//         if(n==0) return 1;
//         if(n<0) return 0;
//         if(dp[n] != -1) return dp[n];
        
//         return dp[n] = solve(n-1, dp) + solve(n-2, dp);
//     }
    
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        if(n<=2) return n;
//         vector<int> dp(n+1, 0);
//         dp[1] = 1;
//         dp[2] = 2;
        
//         for(int i=3; i<=n; i++) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
        
        // return dp[n];
        
        int pre1=1, pre2=2;
        for(int i=3; i<=n; i++) {
            int current = pre1 + pre2;
            pre1 = pre2;
            pre2 = current;
        }
        
        return pre2;
    }
};