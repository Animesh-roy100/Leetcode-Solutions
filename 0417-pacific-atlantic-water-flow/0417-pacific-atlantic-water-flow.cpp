class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> ans;
        
        vector<vector<bool>> isPacific(m, vector<bool> (n, false));
        vector<vector<bool>> isAtlantic(m, vector<bool> (n, false));
        
        queue<pair<int, int>> PacificQ;
        queue<pair<int, int>> AtlanticQ;
        
        for(int i=0; i<m; i++) {
            PacificQ.push({i, 0});
            isPacific[i][0]=true;
            AtlanticQ.push({i, n-1});
            isAtlantic[i][n-1]=true;
        }
        
        for(int j=0; j<n; j++) {
            PacificQ.push({0, j});
            isPacific[0][j]=true;
            AtlanticQ.push({m-1, j});
            isAtlantic[m-1][j]=true;
        }
        
        bfs(PacificQ, isPacific, heights);
        bfs(AtlanticQ, isAtlantic, heights);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isPacific[i][j] and isAtlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
    
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &isOcean, vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto &it: dir) {
                int X = x + it.first;
                int Y = y + it.second;
                
                if(X<0 or X>=m or Y<0 or Y>=n or isOcean[X][Y] or heights[X][Y] < heights[x][y]) continue;
                
                isOcean[X][Y] = true;
                q.push({X, Y});
            }
        }
    }
};