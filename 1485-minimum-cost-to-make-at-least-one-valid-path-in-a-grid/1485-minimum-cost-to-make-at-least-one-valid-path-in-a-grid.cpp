class Solution {
public:
    typedef pair<int, pair<int, int>> piii;
    typedef pair<int, int> pii;

    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up

        // priority_queue<piii, vector<piii>, greater<piii>> pq;
        // pq.push({0, {0, 0}});  // {cost, {x, y}}
        deque<pii> dq;
        dq.push_front({0, 0});

        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));
        cost[0][0] = 0;

        while(!dq.empty()) {
            // int currCost = pq.top().first;
            // int x = pq.top().second.first;
            // int y = pq.top().second.second;
            // pq.pop();

            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            // if(currCost > cost[x][y]) continue;

            int ind=0;
            for(auto it: dir) {
                int newX = x + it.first;
                int newY = y + it.second;
                ind++;
                if(newX<0 or newX>=m or newY<0 or newY>=n) continue;

                int newCost=cost[x][y];
                // check if direction is same as previous
                if(grid[x][y] != ind) {
                    newCost++;
                }

                if(newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    // pq.push({newCost, {newX, newY}});

                    if(grid[x][y] == ind) {
                        dq.push_front({newX, newY});
                    } else {
                        dq.push_back({newX, newY});
                    }
                }
            }
        }

        return cost[m-1][n-1];
    }
};