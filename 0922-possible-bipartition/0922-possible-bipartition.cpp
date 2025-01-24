class Solution {
public:
    bool dfs(int idx, int color, vector<vector<int>> &graph, vector<int> &vis) {
        vis[idx] = color;

        for(auto node: graph[idx]) {
            if(vis[node] == -1) {
                if(!dfs(node, !color, graph, vis)) return false;
            } else if(vis[node] == vis[idx]) return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto pair: dislikes) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        vector<int> vis(n+1, -1);
        for(int i=1; i<=n; i++) {
            if(vis[i] == -1) {
                if(!dfs(i, 0, graph, vis)) return false;
            }
        }

        return true;
    }
};