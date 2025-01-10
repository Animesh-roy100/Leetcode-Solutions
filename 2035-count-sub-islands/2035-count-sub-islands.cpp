class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &vis, bool &flag) {
        int m=grid1.size(), n=grid1[0].size();
        if(i<0 or i>=m or j<0 or j>=n or vis[i][j] or grid2[i][j]==0) return;
        vis[i][j] = true;
        if(grid1[i][j] == 0) {
            flag=false;
        }

        dfs(i+1, j, grid1, grid2, vis, flag);
        dfs(i-1, j, grid1, grid2, vis, flag);
        dfs(i, j+1, grid1, grid2, vis, flag);
        dfs(i, j-1, grid1, grid2, vis, flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int count=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1 and !vis[i][j]) {
                    bool flag=true;
                    dfs(i, j, grid1, grid2, vis, flag);
                    if(flag) count++;
                }
            }
        }

        return count;
    }
};