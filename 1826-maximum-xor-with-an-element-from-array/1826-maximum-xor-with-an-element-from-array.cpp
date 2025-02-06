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

    int findMaximumXOR(int num) {
        TrieNode* temp = root;
        int ans=0;
        for(int i=31; i>=0; i--) {
            int bit = (1 << i) & num;
            if(bit) {
                if(temp->child[0] != nullptr) {
                    ans += (1<<i);
                    temp = temp->child[0];
                } else {
                    temp = temp->child[1];
                }
            } else {
                if(temp->child[1] != nullptr) {
                    ans += (1<<i);
                    temp = temp->child[1];
                } else {
                    temp = temp->child[0];
                }
            }
        }

        return ans;
    }
};

class Solution {
public:

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        // store the index
        for(int i=0; i<queries.size(); i++) queries[i].push_back(i);

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });

        vector<int> ans(queries.size(), -1);
        int i=0;
        Trie t;
        for(auto query: queries) {  
            int x = query[0];
            int m = query[1];
            int idx = query[2];
            while(i<n) {
                if(nums[i] <= m) {
                    t.insert(nums[i]);
                    i++;
                } else {
                    break;
                }
            }

            if(i!=0) {
                ans[idx] = t.findMaximumXOR(x);
            }            
        }

        return ans;
    }
};