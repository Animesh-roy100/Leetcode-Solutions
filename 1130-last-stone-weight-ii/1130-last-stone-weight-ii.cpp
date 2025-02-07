class Solution {
public:
    int solve(int i, int target, vector<int> &stones, vector<vector<int>> &dp) {
        if(i==0) return 0;

        if(dp[i][target] != -1) return dp[i][target];

        int include=0;
        if(stones[i-1] <= target) {
            include = stones[i-1] + solve(i-1, target-stones[i-1], stones, dp);
        }
        int exclude = solve(i-1, target, stones, dp);

        return dp[i][target] = max(include, exclude);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int stone: stones) sum+=stone;

        int target = sum/2;

        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        int maxSubset = solve(n, target, stones, dp);

        return sum - 2 * maxSubset;
    }
};