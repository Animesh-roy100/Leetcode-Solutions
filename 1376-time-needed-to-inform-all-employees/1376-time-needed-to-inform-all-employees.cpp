class Solution {
public:
    int solve(vector<vector<int>> &adj, int headID, vector<int> &informTime) {
        int time = 0;
        
        for(int ind: adj[headID]) {
            time = max(time, informTime[headID] + solve(adj, ind, informTime));
        }
        
        return time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return solve(adj, headID, informTime);
    }
};