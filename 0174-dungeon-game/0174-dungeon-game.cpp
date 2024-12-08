class Solution {
public:
    // int solve(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &dp) {
//         int m=dungeon.size(), n = dungeon[0].size();
//         if(i == m or j == n) return INT_MAX;
//         if(i == m-1 and j == n-1) return max(1, 1 - dungeon[i][j]);
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int right = solve(i, j+1, dungeon, dp);
//         int down = solve(i+1, j, dungeon, dp);
        
//         return dp[i][j] = max(1, min(right, down) - dungeon[i][j]);
//     }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n = dungeon[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(0, 0, dungeon, dp);
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};