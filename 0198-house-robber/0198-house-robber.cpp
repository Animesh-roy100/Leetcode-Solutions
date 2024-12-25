class Solution {
public:
    int solve(int n, vector<int> &nums, vector<int> &dp) {
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int take = nums[n-1] + solve(n-2, nums, dp);
        int notTake = solve(n-1, nums, dp);
        
        return dp[n] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return solve(n, nums, dp);
    }
};