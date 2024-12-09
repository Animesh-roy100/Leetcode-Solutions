class Solution {
public:
    int solve(int i, vector<int> &nums, int sum, vector<vector<int>> &dp) {
        if(sum==0) return true;
        if(i==0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        if(nums[i-1] <= sum) {
            return dp[i][sum] = solve(i-1, nums, sum-nums[i-1], dp) || solve(i-1, nums, sum, dp);
        } else {
            return dp[i][sum] = solve(i-1, nums, sum, dp);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num: nums) sum+=num;
        if(sum%2 == 1) return false;
        vector<vector<int>> dp(n+1, vector<int> (sum/2 + 1, -1));
        return solve(n, nums, sum/2, dp);
    }
};