class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(), n = obs[0].size();
        if(m==1 and n==1 and obs[0][0]==0) return 1;
        if(obs[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=1; i<m; i++) {
            if(obs[i][0] == 1) break;
            dp[i][0] = 1;
        }
        
        for(int j=1; j<n; j++) {
            if(obs[0][j] == 1) break;
            dp[0][j] = 1;
        }
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(obs[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};