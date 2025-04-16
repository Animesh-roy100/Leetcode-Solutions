class Solution {
public:

    int solve(int i, vector<int> &dp, vector<vector<int>> &jobs, vector<int> &startTime) {
        if(i == startTime.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int nextIdx = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();

        int maxProfit = max(solve(i+1, dp, jobs, startTime), jobs[i][2] + solve(nextIdx, dp, jobs, startTime));

        return dp[i] = maxProfit; 
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n=startTime.size();
        for(int i=0; i<n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for(int i=0; i<n; i++) {
            startTime[i] = jobs[i][0];
        }

        vector<int> dp(n, -1);

        return solve(0, dp, jobs, startTime);
    }
};