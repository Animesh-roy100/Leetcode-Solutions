class Solution {
public:
    bool solve(vector<int> &nums, int sum) {
        int n=nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                // if(j==0) dp[i][j] = true;
                // else {
                    if(nums[i-1] <= j) {
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                // }
            }
        }
        
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num: nums) sum += num;
        if(sum%2 != 0) return false;
        
        return solve(nums, sum/2);
    }
};