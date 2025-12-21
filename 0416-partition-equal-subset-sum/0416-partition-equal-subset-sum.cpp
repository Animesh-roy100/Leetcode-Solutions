class Solution {
public:
    bool solve(int i, vector<int> &nums, int sum, vector<vector<int>> &dp) {
        if(sum == 0) return true;
        if(i == nums.size() or sum < 0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];

        return dp[i][sum] = solve(i+1, nums, sum-nums[i], dp) || solve(i+1, nums, sum, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (sum/2+1, -1));
        return solve(0, nums, sum/2, dp);
    }
};