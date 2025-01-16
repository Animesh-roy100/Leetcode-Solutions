class Solution {
public:
    const int MOD = 1e9+7;

    int solve(int n, vector<int> &dp) {
        if(n<0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5; 
        
        if(dp[n] != -1) return dp[n];

        return dp[n] = ((2*solve(n-1, dp))%MOD + solve(n-3, dp)%MOD) % MOD;
    }

    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};