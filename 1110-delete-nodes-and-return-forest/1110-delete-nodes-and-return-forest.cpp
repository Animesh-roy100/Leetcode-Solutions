/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(int &node: to_delete) st.insert(node);
        
        vector<TreeNode*> ans;
        
        if(st.find(root->val) == st.end()) {
            ans.push_back(root);
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
            if(curr->left and st.find(curr->left->val) != st.end()) {
                curr->left = NULL;
            }
            if(curr->right and st.find(curr->right->val) != st.end()) {
                curr->right = NULL;
            }
            
            if(st.find(curr->val) != st.end()) {
                if(curr->left) ans.push_back(curr->left);
                if(curr->right) ans.push_back(curr->right);
            }
        }
        
        return ans;
    }
};