class Solution {
public:
    bool solve(vector<int> &nums, int n, int sum, vector<vector<int>> &dp) {
        if(sum==0) return true;
        if(n==0) return false;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        if(nums[n-1] <= sum) {
            return dp[n][sum] = solve(nums, n-1, sum-nums[n-1], dp) || solve(nums, n-1, sum, dp);
        } else {
            return dp[n][sum] = solve(nums, n-1, sum, dp);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num: nums) sum+=num;
        int n=nums.size();
        if(sum%2 == 1) return false;
        sum = sum/2;
        
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return solve(nums, nums.size(), sum, dp);
    }
};