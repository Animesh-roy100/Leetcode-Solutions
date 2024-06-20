class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size()) return;
        if(grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        bfs(grid, i+1, j);
        bfs(grid, i-1, j);
        bfs(grid, i, j+1);
        bfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int numIslands=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    numIslands++;
                }
            }
        }
        
        return numIslands;
    }
};