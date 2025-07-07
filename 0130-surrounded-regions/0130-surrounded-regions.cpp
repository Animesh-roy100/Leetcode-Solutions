class Solution {
public:
    void solve(int i, int j, int m, int n, vector<vector<char>> &board) {
        if(i<0 or i>=m or j<0 or j>=n or board[i][j] != 'O') return;

        board[i][j] = 'A';

        solve(i+1, j, m, n, board);
        solve(i-1, j, m, n, board);
        solve(i, j-1, m, n, board);
        solve(i, j+1, m, n, board);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();

        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') {
                solve(i, 0, m, n, board);
            }
            if(board[i][n-1] == 'O') {
                solve(i, n-1, m, n, board);
            }
        }

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O') {
                solve(0, j, m, n, board);
            }
            if(board[m-1][j] == 'O') {
                solve(m-1, j, m, n, board);
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'A') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};