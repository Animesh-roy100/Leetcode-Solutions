class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // priority queue (dijkstra's algo)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<int> dist(n, INT_MAX);
        
        // adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        dist[src] = 0;
        pq.push({0, {0, src}}); // {stops, {dist, node}}
        
        while(!pq.empty() and k>=0) {
            auto info = pq.top();
            int stops = info.first;
            int node = info.second.second;
            int dis = info.second.first;
            pq.pop();
            
            // cout<<"info: "<<stops<<" "<<node<<" "<<dis<<endl;
            
            if(stops>k) continue;
            
            for(auto it: adj[node]) {
                int currNode = it.first;
                int currDist = it.second;
                if(currDist + dis < dist[currNode]) {
                    dist[currNode] = currDist + dis;
                    pq.push({stops+1, {dist[currNode], currNode}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
     }
};