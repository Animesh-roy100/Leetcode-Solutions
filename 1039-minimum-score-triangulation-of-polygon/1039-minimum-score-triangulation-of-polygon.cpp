class Solution {
public:
    int solve(vector<int> &values, int i, int j, vector<vector<int>> &dp) {
        if(i==j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int minVal = INT_MAX;
        for(int k=i; k<j; k++) {
            int val = solve(values, i, k, dp) + solve(values, k+1, j, dp) + values[i-1]*values[k]*values[j];
            minVal = min(minVal, val);
        }
        dp[i][j] = minVal;
        return minVal;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 1, n-1, dp);
    }
};