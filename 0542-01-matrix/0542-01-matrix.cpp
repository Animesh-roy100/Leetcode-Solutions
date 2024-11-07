class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> ans(m, vector<int> (n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool> (n , false));
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto &it: dir) {
                int X = x + it.first;
                int Y = y + it.second;
                
                if(X<0 or X>=m or Y<0 or Y>=n or vis[X][Y]) continue;
                
                q.push({X, Y});
                vis[X][Y] = true;
                ans[X][Y] = min(ans[X][Y], 1 + ans[x][y]);
            }
        }
        
        return ans;
    }
};