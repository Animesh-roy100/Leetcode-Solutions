class Solution {
public:
    int ans=0;

    int solve(int node, int n, vector<int> &cost) {
        if(node >= n) return 0;

        // if(dp[node] != -1) return dp[node];

        int left = solve(2*node+1, n, cost);
        int right = solve(2*node+2, n, cost);

        ans += abs(left-right);

        return cost[node] + max(left, right);
    }

    int minIncrements(int n, vector<int>& cost) {
        // vector<int> dp(n+1, -1);
        solve(0, n, cost);
        return ans;
    }
};