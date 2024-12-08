class Solution {
public:
    int solve(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp) {
        int n=days.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int dayCost = costs[0] + solve(idx+1, days, costs, dp);
        
        int currIdx;
        for(currIdx=idx; currIdx<n and days[currIdx] < days[idx] + 7; currIdx++);
        int weekCost = costs[1] + solve(currIdx, days, costs, dp);
        
        for(currIdx=idx; currIdx<n and days[currIdx] < days[idx] + 30; currIdx++);
        int monthCost = costs[2] + solve(currIdx, days, costs, dp);
        
        return dp[idx] = min({dayCost, weekCost, monthCost});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, dp);
    }
};