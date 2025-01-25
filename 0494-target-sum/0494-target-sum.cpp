class Solution {
public:
    int solve(int idx, int total, vector<int> &nums, vector<vector<int>> &dp) {
        if(idx == nums.size()) {
            if(total == 0) return 1;
            else return 0;
        }

        if(dp[idx][total] != -1) return dp[idx][total];

        if(nums[idx] <= total) {
            return dp[idx][total] = solve(idx+1, total-nums[idx], nums, dp) + solve(idx+1, total, nums, dp);
        } else {
            return dp[idx][total] = solve(idx+1, total, nums, dp);
        }

        return dp[idx][total];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto num: nums) sum+=num;

        int total = sum-target;
        if(total%2 != 0 or total<0) return 0;
        total /= 2;

        vector<vector<int>> dp(nums.size()+1, vector<int> (total+1, -1));
        return solve(0, total, nums, dp);
    }
};