class Solution {
public:
    int solve(int m, int n, int r, int c, vector<vector<int>> &dp) {
        if(r<0 or r>=m or c<0 or c>=n) return 0;
        if(r==m-1 and c==n-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];

        int paths=0;
        paths += solve(m, n, r, c+1, dp);
        paths += solve(m, n, r+1, c, dp);

        return dp[r][c] = paths;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m, n, 0, 0, dp);
    }
};