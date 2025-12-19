class Solution {
public:
    const int MOD = 1e9+7;
    vector<pair<int,int>> dir{{-1,0}, {1, 0}, {0, -1}, {0, 1}};

    int solve(int m, int n, int r, int c, int maxMove, vector<vector<vector<int>>> &dp) {
        if(r<0 or r>=m or c<0 or c>=n) return 1;
        if(maxMove==0) return 0;
        if(dp[maxMove][r][c] != -1) return dp[maxMove][r][c];

        long long paths=0;
        for(auto it: dir) {
            paths = (paths + solve(m, n, r+it.first, c+it.second, maxMove-1, dp)) % MOD;
        }

        return dp[maxMove][r][c] = paths;
    }

    int findPaths(int m, int n, int maxMove, int r, int c) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int> (n, -1)));
        return solve(m, n, r, c, maxMove, dp);
    }
};