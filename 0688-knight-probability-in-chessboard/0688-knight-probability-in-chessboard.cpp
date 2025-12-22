class Solution {
public:
    vector<pair<int, int>> dir{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    double solve(int n, int k, int r, int c, vector<vector<vector<double>>> &dp) {
        if(r<0 or r>=n or c<0 or c>=n) return 0;
        if(k == 0) return 1;

        if(dp[r][c][k] != -1) return dp[r][c][k];

        double prob=0;

        for(auto &it: dir) {
            prob += solve(n, k-1, r+it.first, c+it.second, dp)/8;
        }

        return dp[r][c][k] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k+1, -1)));

        return solve(n, k, row, column, dp);
    }
};