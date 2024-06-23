class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxX=0, maxY=0, minX=INT_MAX, minY=INT_MAX;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    maxX = max(maxX, i);
                    minX = min(minX, i);
                    maxY = max(maxY, j);
                    minY = min(minY, j);
                }
            }
        }
        
        return (maxX-minX+1)*(maxY-minY+1);
    }
};