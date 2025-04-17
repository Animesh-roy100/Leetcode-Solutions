class Solution {
public:
    bool solve(int i, int j, int n, int m, string &s, string &p, vector<vector<int>> &dp) {
        if(i==n and j==m) return true;
        if(i<n and j==m) return false;

        if(i==n and j<m) {
            for(int idx=j; idx<m; idx++) {
                if(p[idx] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] or p[j] == '?') {
            return dp[i][j] = solve(i+1, j+1, n, m, s, p, dp);
        }

        if(p[j] == '*') {
            return dp[i][j] = solve(i+1, j, n, m, s, p, dp) || solve(i, j+1, n, m, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, n, m, s, p, dp);
    }
};