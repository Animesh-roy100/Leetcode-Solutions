class Solution {
public:
//     int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
//         int n=matrix.size();
//         if(j<0 or j>=n) return INT_MAX;
//         if(i == n-1) return dp[i][j] = matrix[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         return dp[i][j] = matrix[i][j] + min({dfs(i+1, j-1, matrix, dp), dfs(i+1, j, matrix, dp), dfs(i+1, j+1, matrix, dp)});
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int ans=INT_MAX;
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // for(int j=0; j<n; j++) {
        //     ans = min(ans, dfs(0, j, matrix, dp));
        // }
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n; j++) {
                int left = (j > 0) ? matrix[i+1][j-1] : 1e8;
                int middle = matrix[i+1][j];
                int right = (j < n-1) ? matrix[i+1][j+1] : 1e8;
                
                matrix[i][j] += min({left, middle, right});
            }
        }
        
        // return ans;
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};