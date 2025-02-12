class TrieNode {
public:
    vector<string> suggestions;
    unordered_map<char, TrieNode*> children;
    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *temp = root;
        for(char c: word) {
            if(temp->children.find(c) == temp->children.end()) {
                temp->children[c] = new TrieNode();
            }
            if(temp->suggestions.size() < 3) temp->suggestions.push_back(word);
            temp = temp->children[c];
        }
        if(temp->suggestions.size() < 3) temp->suggestions.push_back(word);
    }

    vector<vector<string>> search(string word) {
        vector<vector<string>> ans;
        TrieNode* temp = root;
        for(char c: word) {
            if(temp->children.find(c) != temp->children.end()) {
                temp = temp->children[c];
                ans.push_back(temp->suggestions);
            } else break;
        }

        while(ans.size() < word.size()) {
            ans.push_back({});
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        sort(products.begin(), products.end());
        for(auto &product: products) t.insert(product);

        return t.search(searchWord);
    }
};