class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int islands=0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1' and !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        // vis[x][y] = true;
                        
                        for(auto &it: dir) {
                            int X = x+it.first;
                            int Y = y+it.second;
                            
                            if(X<0 or X>=m or Y<0 or Y>=n or vis[X][Y]==true or grid[X][Y]=='0') continue;
                            
                            q.push({X, Y});
                            vis[X][Y] = true;
                        }
                    }
                    islands++;
                }
                
                // vis[i][j]=true;
            }
        }
        return islands;
    }
};