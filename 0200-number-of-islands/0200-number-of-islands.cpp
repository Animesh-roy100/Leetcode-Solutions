class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        int m=grid.size(), n=grid[0].size();
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j] == '0' or vis[i][j]) return;
        vis[i][j] = true;
        dfs(i+1, j, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int count=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] and grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        
        return count;
    }
};