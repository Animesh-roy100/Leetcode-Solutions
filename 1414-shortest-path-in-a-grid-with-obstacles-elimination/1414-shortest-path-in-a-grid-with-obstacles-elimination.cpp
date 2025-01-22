class Solution {
public:
    typedef tuple<int, int, int> tiii; // {obs, x, y}
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<tiii> q;
        q.push({k, 0, 0}); // {obs, x, y}

        vector<vector<vector<bool>>> vis(m, vector<vector<bool>> (n, vector<bool> (k+1, false)));
        vis[0][0][k] = true;

        int steps=0;
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                auto [obs, x, y] = q.front();
                q.pop();

                if(x==m-1 and y==n-1) return steps;

                for(auto it: dir) {
                    int newX = it.first + x;
                    int newY = it.second + y;

                    if(newX<0 or newX>=m or newY<0 or newY>=n or vis[newX][newY][obs]) continue;
                    int newObs = obs - grid[newX][newY];

                    if(newObs>=0 and !vis[newX][newY][newObs]) {
                        vis[newX][newY][newObs] = true;
                        q.push({newObs, newX, newY});
                    }
                }
            } 
            steps++;
        }

        return -1;
    }
};