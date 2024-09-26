class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), parent(n, -1);
        int lastIndex = 0, ans = 1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if((nums[i]%nums[j] == 0 or nums[j]%nums[i] == 0) and dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
            if(ans < dp[i]) {
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> subset;
        for(int i = lastIndex; i != -1; i = parent[i]) {
            subset.push_back(nums[i]);
        }
        
        reverse(subset.begin(), subset.end());
        
        return subset;
    }
};