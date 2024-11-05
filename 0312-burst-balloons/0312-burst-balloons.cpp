class Solution {
public:
    int solve(vector<int> &balloons, int i, int j, vector<vector<int>> &dp) {
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxCoins = 0;
        
        for(int k=i; k<=j; k++) {
            int coins = solve(balloons, i, k-1, dp) + solve(balloons, k+1, j, dp) + balloons[i-1]*balloons[k]*balloons[j+1];
            
            maxCoins = max(maxCoins, coins);
        }
    
        return dp[i][j] = maxCoins;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> balloons(n+2, 0);
        balloons[0] = 1;
        for(int i=1; i<=n; i++) {
            balloons[i] = nums[i-1];
        }
        balloons[n+1] = 1;
        
        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
        
        return solve(balloons, 1, n, dp);
    }
};