class Solution {
public:
    vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isCycle(int i, int j, int parentX, int parentY, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        vis[i][j] = true;

        for(auto it: dir) {
            int newX = it.first + i;
            int newY = it.second + j;
            if(newX<0 or newX>=grid.size() or newY<0 or newY>=grid[0].size()) continue;

            // if the current node is the parent as well
            if(newX==parentX and newY==parentY) continue;

            if(grid[i][j] == grid[newX][newY]) {
                if(vis[newX][newY] or isCycle(newX, newY, i, j, grid, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) {
                    if(isCycle(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }

        return false;
    }
};