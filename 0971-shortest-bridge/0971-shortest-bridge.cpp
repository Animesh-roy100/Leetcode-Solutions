class Solution {
public:
    void dfs(int i, int j, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, queue<pair<int, int>> &q) {
        if(i<0 or i>=n or j<0 or j>=n or vis[i][j] or grid[i][j] == 0) return;

        vis[i][j] = true;
        q.push({i, j});
        for(auto it: dir) {
            dfs(i+it.first, j+it.second, n, grid, vis, dir, q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int flips=0;

        for(int i=0; i<n; i++) {
            bool found=false;
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, n, grid, vis, dir, q);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto it: dir) {
                    int newX = x + it.first;
                    int newY = y + it.second;
                    if(newX<0 or newX>=n or newY<0 or newY>=n or vis[newX][newY]) continue;

                    if(grid[newX][newY] == 1) return flips;
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
            flips++;
        }

        return flips;
    }
};