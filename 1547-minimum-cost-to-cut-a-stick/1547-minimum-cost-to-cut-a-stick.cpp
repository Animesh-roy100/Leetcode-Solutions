class Solution {
public:
    int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for(int k=i; k<=j; k++) {
            int cost = solve(cuts, i, k-1, dp) + solve(cuts, k+1, j, dp) + (cuts[j+1] - cuts[i-1]);
            
            minCost = min(minCost, cost);
        }
        
        return dp[i][j] = minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));
        
        return solve(cuts, 1, cuts.size()-2, dp);
    }
};