class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* temp = root;
        for(int i=31; i>=0; i--) {
            int bit = (1 << i) & num;
            if(bit) {
                if(temp->child[1] == nullptr) temp->child[1] = new TrieNode();
                temp = temp->child[1];
            } else {
                if(temp->child[0] == nullptr) temp->child[0] = new TrieNode();
                temp = temp->child[0];
            }
        }
    }

    int findMaximum(int num) {
        TrieNode* temp = root;
        int res=0;
        for(int i=31; i>=0; i--) {
            int bit = (1 << i) & num;
            if(bit) {
                if(temp->child[0] != nullptr) {
                    res += (1<<i);
                    temp = temp->child[0];
                } else {
                    temp = temp->child[1];
                }
            } else {
                if(temp->child[1] != nullptr) {
                    res += (1<<i);
                    temp = temp->child[1];
                } else {
                    temp = temp->child[0];
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int num: nums) t.insert(num);

        int ans=0;
        for(int num: nums) {
            ans = max(ans, t.findMaximum(num));
        }

        return ans;
    }
};