class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &vis) {
        int n=isConnected.size();
        
        vis[node] = true;
        
        for(int i=0; i<n; i++) {
            if(isConnected[node][i]==1 and !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        vector<bool> vis(n, false);
        
        int ans=0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};