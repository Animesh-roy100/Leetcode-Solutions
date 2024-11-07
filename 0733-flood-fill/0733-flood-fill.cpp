class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(), n=image[0].size();
        
        vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int prevNum = image[sr][sc];
        
        if(prevNum == color) return image;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(image[x][y] == prevNum) image[x][y] = color; 
            
            for(auto &it: dir) {
                int newX = x + it.first;
                int newY = y + it.second;
                
                if(newX<0 or newX>=m or newY<0 or newY>=n or image[newX][newY] != prevNum) continue;
                
                q.push({newX, newY});
            }
        }
        
        return image;
    }
};