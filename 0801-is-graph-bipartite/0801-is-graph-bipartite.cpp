class Solution {
public:
    bool dfs(int idx, int color, vector<vector<int>> &graph, vector<int> &vis) {
        vis[idx] = color;

        for(auto node: graph[idx]) {
            if(vis[node] == -1) {
                if(!dfs(node, !color, graph, vis)) return false;
            } else if(vis[node] == vis[idx]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, -1); // color will be either 0 or 1
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                if(!dfs(i, 0, graph, vis)) return false;
            }
        }
        return true;
    }
};