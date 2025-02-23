class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i>=s1.length()) {
            return s2.length() - j;
        }

        if(j>=s2.length()) {
            return s1.length() - i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans;
        if(s1[i] == s2[j]) {
            ans = solve(i+1, j+1, s1, s2, dp);
        } else {
            // 1 + min({replace, delete, insert})
            ans = 1 + min({solve(i+1, j+1, s1, s2, dp), solve(i+1, j, s1, s2, dp), solve(i, j+1, s1, s2, dp)}); 
        }

        return dp[i][j] = ans;
    }

    int minDistance(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};