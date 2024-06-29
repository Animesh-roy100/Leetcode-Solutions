class Solution {
private:
    void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[i] = true;
        
        for(auto &node: adj[i]) {
            if(!vis[node]) {
                dfs(node, vis, adj);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0; i<n; i++) {
            vector<bool> vis(n, false);
            dfs(i, vis, adj);
            
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(vis[j]) ans[j].push_back(i);
            }
        }
        
        return ans;
    }
};