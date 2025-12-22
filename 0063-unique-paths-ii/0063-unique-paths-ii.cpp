class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {0, 1}};

    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j] == 1) return 0;
        if(i == m-1 and j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int paths=0;
        for(auto &it: dir) {
            paths += solve(i+it.first, j+it.second, m, n, grid, dp);
        }

        return dp[i][j] = paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1 or grid[0][0] == 1) return 0;

        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(0, 0, m, n, grid, dp);
    }
};