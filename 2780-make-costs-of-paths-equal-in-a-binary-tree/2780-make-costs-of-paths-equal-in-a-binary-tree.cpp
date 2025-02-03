class Solution {
public:
    int ans=0;

    int solve(int node, int n, vector<int> &cost) {
        // if this node doesn't exist(if it is greater that n) then return 0
        if(node > n) return 0;

        // the left and right path cost
        int left = solve(2*node, n, cost);
        int right = solve(2*node+1, n, cost);

        // store the difference needed to make the left and right path equal
        ans += abs(left-right);

        // return the current path
        return cost[node-1] + max(left, right);
    }

    int minIncrements(int n, vector<int>& cost) {
        // vector<int> dp(n+1, -1);
        solve(1, n, cost);
        return ans;
    }
};