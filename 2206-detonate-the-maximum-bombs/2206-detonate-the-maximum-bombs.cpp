class Solution {
public:
    void dfs(int idx, vector<vector<int>> &graph, int &count, vector<bool> &vis) {
        vis[idx] = true;
        count++;
        for(auto node: graph[idx]) {
            if(!vis[node]) dfs(node, graph, count, vis);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> graph(n);

        // make adjacency list
        for(int i=0; i<n; i++) {
            long x = bombs[i][0];
            long y = bombs[i][1];
            long r = bombs[i][2];

            for(int j=0; j<n; j++) {
                if(i != j) {
                    long x1 = abs(x - bombs[j][0]);
                    long y1 = abs(y - bombs[j][1]);
                    if(x1*x1 + y1*y1 <= r*r) {
                        graph[i].push_back(j);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int count=0;
            vector<bool> vis(n, false);
            dfs(i, graph, count, vis);
            ans = max(ans, count);
        }

        return ans;
    }
};