class Trie{
public:
    bool isCompleteWord;
    Trie* children[26];

    Trie() {
        isCompleteWord = false;
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
public:
    Trie* root;

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* node = root;
        for(auto ch: word) {
            int idx = ch-'a';
            if(node->children[idx] == NULL) node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->isCompleteWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }

    bool searchHelper(string word, Trie* root) {
        Trie* node = root;
        for(int i=0; i<word.length(); i++) {
            if(word[i] == '.') {
                for(auto it: node->children) {
                    if(it and searchHelper(word.substr(i+1), it)) return true;
                }
                return false;
            }
            int idx = word[i]-'a';
            if(node->children[idx] == NULL) return false;
            node = node->children[idx];
        }

        return node->isCompleteWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */