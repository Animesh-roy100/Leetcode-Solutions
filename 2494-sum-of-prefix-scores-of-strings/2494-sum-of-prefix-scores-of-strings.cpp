class TrieNode {
public:
    TrieNode* children[26];
    int count;

    TrieNode() {
        count=0;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word) {
            int idx = c-'a';
            if(curr->children[idx] == nullptr) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
            curr->count++;
        }
    }

    int countPrefix(string word) {
        int ans=0;
        TrieNode* curr = root;
        for(char c: word) {
            int idx = c-'a';
            ans += curr->children[idx]->count;
            curr = curr->children[idx];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;

        for(string word: words) t.insert(word);

        vector<int> ans;
        for(string word: words) ans.push_back(t.countPrefix(word));

        return ans; 
    }
};