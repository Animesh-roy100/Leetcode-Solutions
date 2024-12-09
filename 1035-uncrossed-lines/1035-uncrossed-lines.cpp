class Solution {
public:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
        int n=nums1.size(), m=nums2.size();
        if(i<=0 or j<=0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int count=0;
        if(nums1[i-1] == nums2[j-1]) {
            count += 1 + solve(i-1, j-1, nums1, nums2, dp);
        } else {
            count += max(solve(i-1, j, nums1, nums2, dp), solve(i, j-1, nums1, nums2, dp));
        }
        
        return dp[i][j] = count;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, nums1, nums2, dp);
        
//         vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=m; j++) {
//                 if(nums1[i-1] == nums2[j-1]) {
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
        
//         return dp[n][m];
    }
};