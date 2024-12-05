class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // {effort, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // direction
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> efforts(n, vector<int> (m, INT_MAX));
        
        efforts[0][0] = 0;
        pq.push({0, {0, 0}});
        
        
        while(!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            for(auto it: dir) {
                int newX = x + it.first;
                int newY = y + it.second;
                
                if(newX>=0 and newX<n and newY>=0 and newY<m) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[newX][newY]));
                    if(newEffort < efforts[newX][newY]) {
                        efforts[newX][newY] = newEffort;
                        pq.push({efforts[newX][newY], {newX, newY}});    
                    }
                }
            }
        }
        
        return efforts[n-1][m-1];
    }
};