class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans=0;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        
        if(q.empty() or q.size() == n*n) return -1;
        
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto &it: dir) {
                    int X = x + it.first;
                    int Y = y + it.second;

                    if(X<0 or X>=n or Y<0 or Y>=n or vis[X][Y]) continue;

                    vis[X][Y] = true;
                    q.push({X, Y});
                }
            }
            ans++;
        }
        
        return ans-1;
    }
};