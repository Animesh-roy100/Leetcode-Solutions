class Solution {
public:
    vector<pair<int, int>> dir{{-2,-1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {2, 1}, {1, 2}};

    double solve(int n, int r, int c, int k, vector<vector<vector<double>>> &dp) {
        if(r<0 or r>=n or c<0 or c>=n) return 0;
        if(k == 0) return 1;

        if(dp[k][r][c] != -1) return dp[k][r][c];

        double prob = 0;
        for(auto it: dir) {
            prob += solve(n, r+it.first, c+it.second, k-1, dp) / 8;
        }

        return dp[k][r][c] = prob;
    }

    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>> (n, vector<double> (n, -1)));
        return solve(n, r, c, k, dp);
    }
};