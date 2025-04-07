class Solution {
public:
    bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target==0) return true;
        if(i==0 or target<0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        if(nums[i-1] <= target) {
            return dp[i][target] = solve(i-1, target-nums[i-1], nums, dp) || solve(i-1, target, nums, dp);
        } else {
            return dp[i][target] = solve(i-1, target, nums, dp);
        }
    }

    bool canPartition(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(int num: nums) sum+=num;
        if(sum%2!=0) return false; 
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return solve(n, target, nums, dp);
    }
};