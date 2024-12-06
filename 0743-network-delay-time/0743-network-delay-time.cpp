class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(int i=0; i<n; i++) {
            for(auto it: times) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        int maxWait=0;
        for(int i=1; i<=n; i++) {
            maxWait = max(maxWait, dist[i]);
        }
        
        return maxWait == INT_MAX ? -1 : maxWait;
    }
};