class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]) {
                int currNode = it.first;
                int currDist = it.second;
                // cout<<"curr details: "<<currNode<<" "<<currDist<<endl;
                if(dis + currDist < dist[currNode]) {
                    dist[currNode] = dis + currDist;
                    pq.push({dist[currNode], currNode});
                }
            }
        }
        
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};