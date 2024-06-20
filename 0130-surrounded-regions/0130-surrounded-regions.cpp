class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j) {
        int m=board.size(), n=board[0].size();
//         if(i<0 or i>=m or j<0 or j>=n or board[i][j]!='O') return;
        
//         board[i][j] = 'A';
        
//         bfs(board, i+1, j);
//         bfs(board, i-1, j);
//         bfs(board, i, j+1);
//         bfs(board, i, j-1);
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x<0 or x>=m or y<0 or y>=n or board[x][y]!='O') continue;
            
            board[x][y] = 'A';
            
            for(auto &it: dir) {
                q.push({x+it.first, y+it.second});
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {    
                if(i==0  or j==0 or i==m-1 or j==n-1) {
                    if(board[i][j] == 'O') {
                        bfs(board, i, j);
                    }
                }
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};