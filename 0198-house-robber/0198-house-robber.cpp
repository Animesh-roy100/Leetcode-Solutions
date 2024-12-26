class Solution {
public:
//     int solve(int n, vector<int> &nums, vector<int> &dp) {
//         if(n<=0) return 0;
//         if(dp[n] != -1) return dp[n];
        
//         int take = nums[n-1] + solve(n-2, nums, dp);
//         int notTake = solve(n-1, nums, dp);
        
//         return dp[n] = max(take, notTake);
//     }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1, -1);
        // return solve(n, nums, dp);
        if(n==1) return nums[0];
        
//         vector<int> dp(n, 0);
//         dp[0] = nums[0];
//         for(int i=1; i<n; i++) {
//             int take = nums[i] + (i>1 ? dp[i-2] : 0);
//             int notTake = dp[i-1];
        
//             dp[i] = max(take, notTake);
//         }
        
//         return dp[n-1];
        
        int prev1=0; // dp[i-1]
        int prev2=0; // dp[i-2]
        
        for(int i=0; i<n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            
            int current = max(take, notTake);
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};