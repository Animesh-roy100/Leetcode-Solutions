class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors) {
        colors[node] = color;
        for(auto currNode: graph[node]){
            if(colors[currNode] == -1) {
                if(!dfs(currNode, !color, graph, colors)) return false;
            } else if(colors[currNode] == color) return false;
        }
        return true;
    }

    int bfs(int src, int n, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(src);
        vector<int> dist(n+1, -1);
        dist[src] = 0;
        int maxDist = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto currNode: graph[node]) {
                if(dist[currNode] == -1){
                    dist[currNode] = 1 + dist[node];
                    q.push(currNode);
                    maxDist = max(maxDist, dist[currNode]);
                }
            }
        }

        return 1 + maxDist;
    }

    void findComponents(int src, vector<bool> &vis, vector<int> &component, vector<vector<int>> &graph) {
        vis[src] = true;
        component.push_back(src);
        for(auto node: graph[src]){
            if(!vis[node]) findComponents(node, vis, component, graph);
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);
        // make the adjacency list
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> colors(n+1, -1);
        // detect odd cycle using bipartite graph
        for(int i=1; i<=n; i++) {
            if(colors[i] == -1) {
                if(!dfs(i, 0, graph, colors)) return -1;
            }
        }

        // For each connected component, find the maximum number of groups
        
        vector<bool> vis(n+1, false);
        vector<vector<int>> components;

        // calculate components
        for(int i=1; i<=n; i++) {
            if(!vis[i]){
                vector<int> component;
                findComponents(i, vis, component, graph);
                components.push_back(component);
            }
        }

        int totalGroups=0;
        for(auto component: components) {
            int maxGroups=0;
            for(int i=0; i<component.size(); i++) {
                maxGroups = max(maxGroups, bfs(component[i], n, graph));
            }
            totalGroups += maxGroups;
        }

        return totalGroups;
    }
};