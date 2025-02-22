class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {0, 1}};
    void dfs(int i, int j, int m, int n, vector<vector<char>> &board) {
        if(i<0 or i>=m or j<0 or j>=n or board[i][j] != 'X') return;

        board[i][j] = '.';

        for(auto &it: dir) {
            dfs(i+it.first, j+it.second, m, n, board);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        int count=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'X') {
                    dfs(i, j, m, n, board);
                    count++;
                }
            }
        }
        return count;
    }
};