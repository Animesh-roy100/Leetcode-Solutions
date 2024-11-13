class Solution {
public:
    int solve(vector<int> &arr, int i, int k, vector<int> &dp) {
        int n = arr.size();
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxSum = 0, len=0, currMax=0;
        for(int l=i; l<min(n, i+k); l++) {
            len++;
            currMax = max(currMax, arr[l]);
            int sum = len * currMax + solve(arr, l+1, k, dp);
            maxSum = max(maxSum, sum);
        }
        
        return dp[i] = maxSum;
    }
        
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, 0, k, dp);
    }
};