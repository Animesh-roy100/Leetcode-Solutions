class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];

        int steps=0;
        steps += solve(n-1, dp);
        steps += solve(n-2, dp);

        return dp[n] = steps;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};