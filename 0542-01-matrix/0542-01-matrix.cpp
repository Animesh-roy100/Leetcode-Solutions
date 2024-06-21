class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0)  {
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
                int newX = x + it.first;
                int newY = y + it.second;

                if(newX<0 or newX>=m or newY<0 or newY>=n or vis[newX][newY]) continue;
                
                ans[newX][newY] = min(ans[newX][newY], 1+ans[x][y]); 
                vis[newX][newY] = true;

                q.push({newX, newY});
            }
        }
        
        return ans;
    }
};