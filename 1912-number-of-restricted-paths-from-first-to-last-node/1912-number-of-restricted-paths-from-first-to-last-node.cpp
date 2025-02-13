class Solution {
public:
    typedef pair<int, int> pii;
    const int MOD = 1e9+7;

    int solve(int node, vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &dp) {
        if(node == 1) return 1;
        if(dp[node] != -1) return dp[node];

        int ans=0;
        for(auto &[currNode, _]: graph[node]) {
            if(dist[node] < dist[currNode]) {
                ans = (ans + solve(currNode, graph, dist, dp))%MOD;
            }
        }

        return dp[node] = ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto it: edges) {
            int x = it[0], y = it[1], w = it[2];
            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }

        // Dijkstra to find the shortest distance from n to all nodes
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n});
        dist[n] = 0;
        
        int restricted=0;

        while(!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(currDist > dist[node]) continue;

            for(auto &[curr, newDist]: graph[node]) {
                if(currDist + newDist < dist[curr]) {
                    dist[curr] = newDist + currDist;
                    pq.push({dist[curr], curr}); 
                }
            }
        }

        for(int i=1; i<=n; i++) cout<<dist[i]<<" ";

        // DFS to find the restricted path
        vector<int> dp(n+1, -1);
        return solve(n, graph, dist, dp);
    }
};