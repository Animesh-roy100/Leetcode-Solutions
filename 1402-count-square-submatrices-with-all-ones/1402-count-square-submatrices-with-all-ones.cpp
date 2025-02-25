class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));
        int sum=0;

        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 1) {
                dp[i][0] = 1;
                sum++;
            }
        }

        for(int j=1; j<n; j++) {
            if(matrix[0][j] == 1) {
                dp[0][j] = 1;
                sum++;
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                    sum += dp[i][j];
                }
            }
        }

        return sum;
    }
};