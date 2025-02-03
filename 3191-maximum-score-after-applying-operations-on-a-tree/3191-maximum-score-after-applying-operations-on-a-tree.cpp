
class Solution {
public:
    long long dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &values) {
        vis[node] = true;
        long long health=0;
        for(auto curr: graph[node]) {
            if(!vis[curr]) {
                health += dfs(curr, graph, vis, values);
            }
        }

        // if leaf node return its own value
        if(health == 0) return values[node];

        // return the min of total health and value of the node
        return min(health, (long long) values[node]);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long total=0;
        for(auto val: values) total += val;

        vector<bool> vis(n, false);

        return total - dfs(0, graph, vis, values);
    }
};