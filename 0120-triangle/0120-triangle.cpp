class Solution {
public:
//     int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp) {
//         if(i==triangle.size()) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down = triangle[i][j] + solve(triangle, i+1, j, dp);
//         int dia = triangle[i][j] + solve(triangle, i+1, j+1, dp);
        
//         return dp[i][j] = min(down, dia);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solve(triangle, 0, 0, dp);
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<triangle[i].size(); j++) {
                if(i==n-1) dp[i][j] = triangle[i][j];
                else {
                    int down = triangle[i][j] + dp[i+1][j];
                    int dia = triangle[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(down, dia);
                }
            }
        }
        
        return dp[0][0];
    }
};