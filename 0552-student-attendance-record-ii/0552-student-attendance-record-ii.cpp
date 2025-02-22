class Solution {
public:
    const int MOD = 1e9+7;
    typedef long long ll;
    int solve(int n, int absentCount, int consLateCount, vector<vector<vector<int>>> &dp) {
        if(n==0) return 1;

        if(dp[n][absentCount][consLateCount] != -1) return dp[n][absentCount][consLateCount];
        
        ll ans=0;

        // present
        ans = (ans+solve(n-1, absentCount, 0, dp)) % MOD;

        // absent count
        if(absentCount<1) ans = (ans + solve(n-1, absentCount+1, 0, dp)) % MOD;

        // late
        if(consLateCount<2) ans = (ans + solve(n-1, absentCount, consLateCount+1, dp)) % MOD;

        return dp[n][absentCount][consLateCount] = ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));

        return solve(n, 0, 0, dp);
    }
};