class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i]==1) q.push(i);
        }
        
        while(n>2) {
            int size = q.size();
            n -= size;
            while(size-->0) {
                int node = q.front();
                q.pop();
                for(auto it: adj[node]) {
                    if(--degree[it]==1) q.push(it);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};