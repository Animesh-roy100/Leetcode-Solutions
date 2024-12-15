class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j=0; j<n; j++) dp[n-1][j] = grid[n-1][j];
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n; j++) {
                int mini = INT_MAX;
                for(int k=0; k<n; k++) {
                    if(j!=k) mini = min(mini, dp[i+1][k]);
                }
                dp[i][j] = grid[i][j] + mini;
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};