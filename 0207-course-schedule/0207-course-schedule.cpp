class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++) {
            for(auto &node: adj[i]) {
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        
        vector<int> arr;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            arr.push_back(curr);
            for(auto &node: adj[curr]) {
                indegree[node]--;
                if(indegree[node]==0) {
                    q.push(node);
                }
            }
        }
        
        if(arr.size()==n) return true;
        
        return false;
    }
};