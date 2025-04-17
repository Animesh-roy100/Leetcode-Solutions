class Solution {
public:
    bool fun(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        // Base case: both strings are fully matched
        if (i == s.size() && j == p.size()) return true;

        // If pattern is exhausted but string is not
        if (j == p.size()) return false;

        if(dp[i][j] != -1) return dp[i][j];

        // Check if current characters match
        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // If next char in pattern is '*', handle zero or more occurrences
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] = fun(s, p, i, j + 2, dp) || (firstMatch && fun(s, p, i + 1, j, dp));
        }

        // Otherwise, just move both indices if current matches
        if (firstMatch) {
            return dp[i][j] = fun(s, p, i + 1, j + 1, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return fun(s, p, 0, 0, dp);
    }
};
