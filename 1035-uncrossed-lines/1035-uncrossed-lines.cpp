class Solution {
public:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
        int n=nums1.size(), m=nums2.size();
        if(i>=n or j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int count=0;
        if(nums1[i] == nums2[j]) {
            count += 1 + solve(i+1, j+1, nums1, nums2, dp);
        } else {
            count += max(solve(i+1, j, nums1, nums2, dp), solve(i, j+1, nums1, nums2, dp));
        }
        
        return dp[i][j] = count;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};