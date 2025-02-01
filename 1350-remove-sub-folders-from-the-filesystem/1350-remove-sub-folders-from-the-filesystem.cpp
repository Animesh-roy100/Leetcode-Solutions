class TrieNode {
public:
    bool isCompleted;
    TrieNode* children[27]; // 26 for '/'
    TrieNode() {
        isCompleted=false;
        memset(children, 0, sizeof(children));
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string folder) {
        TrieNode* temp = root;
        for(char c : folder) {
            int idx;
            if (c == '/') idx = 26;
            else idx = c-'a';

            if(temp->children[idx] == NULL) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->isCompleted = true;
    }

    bool checkIfSubFolder(string folder) {
        TrieNode *temp = root;
        for(int i=0; i<folder.length(); i++) {
            char c = folder[i];
            int idx;
            if (c == '/') idx = 26;
            else idx = c-'a';

            if (temp->children[idx] == NULL) return false;
            temp = temp->children[idx];

            // Check if the current node is a completed folder and the next character is a slash
            if (temp->isCompleted && i + 1 < folder.size() && folder[i + 1] == '/') {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie t;
        // insert the folders in the trie
        for(string str: folder) t.insert(str);

        vector<string> ans;

        // check if the each folder is a subfolder of another
        for(string str: folder) {
            if(!t.checkIfSubFolder(str)) {
                ans.push_back(str);
            }
        }

        return ans;
    }
};