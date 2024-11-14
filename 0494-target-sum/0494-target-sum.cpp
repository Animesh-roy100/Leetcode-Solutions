class Solution {
public:
    const int MOD = 1e9+7;
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num: nums) sum += num;
        
        int total = sum - target;
        if(total < 0 or total%2 != 0) return 0;
        total /= 2;
        
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (total+1 , 0));
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=total; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = (dp[i-1][j-nums[i-1]] + dp[i-1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][total];
    }
};