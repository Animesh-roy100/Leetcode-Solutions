class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]
        
        for(int i=0; i<n; i++) {
            if(i<=1) prev2=0;
            int take = nums[i] + prev2;
            int notTake = prev1;
            
            int current = max(take, notTake);
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n-1; i++) temp1.push_back(nums[i]);
        for(int i=1; i<n; i++) temp2.push_back(nums[i]);
        
        return max(solve(temp1), solve(temp2));
    }
};