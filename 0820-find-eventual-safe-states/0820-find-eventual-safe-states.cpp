class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            int size=graph[i].size();
            outdegree[i] += size;
            for(int j=0; j<graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(outdegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto newNode: adj[node]) {
                if(--outdegree[newNode] == 0) {
                    q.push(newNode);
                    ans.push_back(newNode);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};