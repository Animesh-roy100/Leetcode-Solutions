class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m=grid.size(), n=grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count=0;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x<0 or x>=m or y<0 or y>=n or grid[x][y]!=1) continue;
            
            grid[x][y] = 0;
            count++;
            
            for(auto &it: dir) {
                q.push({x+it.first, y+it.second});
            }
        }
        cout<<count<<" ";
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};