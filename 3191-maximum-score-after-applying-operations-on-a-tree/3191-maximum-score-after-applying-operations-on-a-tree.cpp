class Solution {
public:
    // int reqHealth=0;
    typedef long long ll;
    ll dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &values) {
        vis[node] = true;
        ll reqHealth = 0;
        for(auto curr: graph[node]) {
            if(!vis[curr]) {
                reqHealth += dfs(curr, graph, vis, values);
            }
        }

        // leaf node
        if(reqHealth == 0) return values[node];

        return min(reqHealth, (ll) values[node]);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        ll total=0;
        for(int val: values) total += val;
        vector<bool> vis(n, false);

        ll reqHealth = dfs(0, graph, vis, values);

        return total - reqHealth;
    }
};