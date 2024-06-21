class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size(), n=grid[0].size();
        
        queue<pair<int, int>> q;
        int countOne=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j]==1) countOne++;
            }
        }
        if(q.empty()) {
            if(countOne>0) return -1;
            else return 0;
        }
        
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            int qsize = q.size();
            // cout<<qsize<<" ";
            while(qsize--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                

                for(auto &it: dir) {
                    int newX = x+it.first;
                    int newY = y+it.second;
                    if(newX<0 or newX>=m or newY<0 or newY>=n or grid[newX][newY]!=1) continue;
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                }
            }
            count++;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return count-1;
    }
};