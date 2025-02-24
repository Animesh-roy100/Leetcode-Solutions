class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> outdegree(m, vector<int> (n, 0));
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(auto& it: dir) {
                    int x = i+it.first;
                    int y = j+it.second;

                    if(x<0 or x>=m or y<0 or y>=n) continue;
                    if(matrix[i][j] < matrix[x][y]) outdegree[i][j]++;
                }
            }
        }

        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(outdegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int ans=0;
        while(!q.empty()) {
            ans++;
            int size=q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto& it: dir) {
                    int newX = x + it.first;
                    int newY = y + it.second;
                    if(newX<0 or newX>=m or newY<0 or newY>=n) continue;

                    if(matrix[x][y] <= matrix[newX][newY]) continue;

                    if(--outdegree[newX][newY] == 0) {
                        q.push({newX, newY});
                    }
                }
            }
        }

        return ans;
    }
};