class Solution {
public:
    int solve(int m, int n, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp) {
        if(r == m-1) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int minCost=INT_MAX;
        for(int i=0; i<n; i++) {
            minCost = min(minCost, grid[r][c] + moveCost[grid[r][c]][i] + solve(m, n, r+1, i, grid, moveCost, dp));
        }

        return dp[r][c] = minCost;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int minCost=INT_MAX;
        for(int i=0; i<n; i++) {
            minCost = min(minCost, solve(m, n, 0, i, grid, moveCost, dp));
        }
        return minCost;
    }
};