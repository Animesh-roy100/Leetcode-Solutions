class Solution {
public:
    int solve(int i, int vowelIdx, int n, vector<vector<int>> &dp) {
        if(vowelIdx == 5) return 0;
        if(i == n) return 1;
        if(dp[i][vowelIdx] != -1) return dp[i][vowelIdx];

        int take = solve(i+1, vowelIdx, n, dp);
        int notTake = solve(i, vowelIdx+1, n, dp);

        return dp[i][vowelIdx] = take + notTake;
    }

    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int> (5, -1));
        return solve(0, 0, n, dp);
    }
};