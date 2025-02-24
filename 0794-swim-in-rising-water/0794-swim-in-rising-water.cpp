class Solution {
public:
    typedef pair<int, pair<int, int>> piii;  // {time, {i, j}} 
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vis[0][0] = true;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == n-1 and y == n-1) return time;

            for(auto &it: dir) {
                int newX = x + it.first;
                int newY = y + it.second;

                if(newX<0 or newX>=n or newY<0 or newY>=n or vis[newX][newY]) continue;
                vis[newX][newY] = true;

                int newTime = max(time, grid[newX][newY]);
                pq.push({newTime, {newX, newY}});
            }
        }

        return -1;
    }
};