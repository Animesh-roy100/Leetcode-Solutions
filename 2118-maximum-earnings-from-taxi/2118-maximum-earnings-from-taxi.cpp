class Solution {
public:
    long long solve(int i, vector<vector<int>> &rides, vector<int> &startTime, vector<long long> &dp) {
        if(i == startTime.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int nextIdx = lower_bound(startTime.begin(), startTime.end(), rides[i][1]) - startTime.begin();

        long long maxEarning = max(solve(i+1, rides, startTime, dp), (rides[i][1] - rides[i][0] + rides[i][2]) + solve(nextIdx, rides, startTime, dp));

        return dp[i] = maxEarning;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());

        vector<long long> dp(rides.size(), -1);

        vector<int> startTime;

        for(int i=0; i<rides.size(); i++) startTime.push_back(rides[i][0]);

        return solve(0, rides, startTime, dp);
    }
};