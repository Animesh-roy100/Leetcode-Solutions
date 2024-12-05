class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7; 
        // adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        vector<long long> paths(n, LLONG_MAX);
        vector<int> ways(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        pq.push({0, 0});
        paths[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]) {
                int currNode = it.first;
                long long currDist = it.second;
                
                if(currDist+dist < paths[currNode]) {
                    paths[currNode] = currDist + dist;
                    ways[currNode] = ways[node];
                    pq.push({paths[currNode], currNode});
                } else if(currDist + dist == paths[currNode]) {
                    ways[currNode] = (ways[node]+ways[currNode])%mod; 
                }
            }
        }
        
        return ways[n-1];
    }
};