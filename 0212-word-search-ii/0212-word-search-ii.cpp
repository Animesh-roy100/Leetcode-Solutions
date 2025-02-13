class TrieNode {
public:
    bool isCompleted;
    TrieNode* children[26];

    TrieNode() {
        isCompleted = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode *temp = root;
        for(char c: word) {
            int idx = c-'a';
            if(temp->children[idx] == nullptr) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->isCompleted = true;
    }


};

class Solution {
private:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int i, int j, vector<vector<char>> &board, TrieNode* node, string &word, vector<string> &res) {
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j] == '#' or node->children[board[i][j]-'a'] == nullptr) return;

        char temp = board[i][j];
        word.push_back(temp);
        node = node->children[temp-'a'];

        if(node->isCompleted) {
            node->isCompleted = false;
            res.push_back(word);
        }

        board[i][j] = '#';

        for(auto &it: dir) dfs(i+it.first, j+it.second, board, node, word, res);

        board[i][j] = temp;
        word.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(string word: words) t.insert(word);

        int m=board.size(), n=board[0].size();
        vector<string> res;
        string word="";

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dfs(i, j, board, t.root, word, res);
            }
        }

        return res;
    }
};