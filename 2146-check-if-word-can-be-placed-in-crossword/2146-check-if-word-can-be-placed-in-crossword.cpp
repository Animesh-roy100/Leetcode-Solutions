class Solution {
private:
    bool checkCanPlaced(string s, string word) {
        if(s.length() != word.length()) return false;
        int i=0;
        for(i=0; i<word.size(); i++) {
            if(word[i] != s[i] and s[i] != ' ') break;
        }
        if(i==word.size()) return true;

        reverse(word.begin(), word.end());
        for(i=0; i<word.size(); i++) {
            if(word[i] != s[i] and s[i] != ' ') break;
        }
        if(i==word.size()) return true;

        return false;
    }

public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();

        for(int i=0; i<m; i++) {
            int count=0;
            for(int j=0; j<n; j++) {
                if(board[i][j] == '#') count=0;
                string s="";
                int k=j;
                while(k<n and board[i][k] != '#') {
                    s+=board[i][k];
                    k++;
                }
                if(checkCanPlaced(s, word)) return true;
                j=k;
            }
        }

        for(int i=0; i<n; i++) {
            int count=0;
            for(int j=0; j<m; j++) {
                if(board[j][i] == '#') count=0;
                string s="";
                int k=j;
                while(k<m and board[k][i] != '#') {
                    s+=board[k][i];
                    k++;
                }
                if(checkCanPlaced(s, word)) return true;
                j=k;
            }
        }

        return false;
    }
};