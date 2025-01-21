class Solution {
public:
    typedef pair<int, pair<int, int>> piii;

    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto it: dir) {
                int newX = it.first + x;
                int newY = it.second + y;

                if(newX<0 or newX>=m or newY<0 or newY>=n) continue;
                
                if(dist + grid[newX][newY] < distance[newX][newY]) {
                    distance[newX][newY] = dist + grid[newX][newY];
                    pq.push({distance[newX][newY], {newX, newY}});
                }
            }
        }

        return distance[m-1][n-1];
    }
};