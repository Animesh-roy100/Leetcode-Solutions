class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto edge: pre) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]) {
                if(--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans.size() != n ? vector<int>{} : ans;
    }
};