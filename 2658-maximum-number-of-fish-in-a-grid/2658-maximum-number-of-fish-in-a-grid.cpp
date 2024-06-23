class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int maxFishes=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    int fishes = grid[i][j];
                    vis[i][j] = true;
                    q.push({i, j});
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(auto &it: dir){
                            int X = x+it.first;
                            int Y = y+it.second;
                            
                            if(X<0 or X>=m or Y<0 or Y>=n or vis[X][Y]==true or grid[X][Y]==0) continue;
                            
                            vis[X][Y]=true;
                            fishes += grid[X][Y];
                            q.push({X, Y});
                        }
                    }
                    maxFishes = max(maxFishes, fishes);
                }
            }
        }
        
        return maxFishes;
    }
};