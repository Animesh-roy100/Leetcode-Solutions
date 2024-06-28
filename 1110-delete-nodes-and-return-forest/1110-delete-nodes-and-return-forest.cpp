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
    void helper(vector<TreeNode*> &ans, unordered_set<int> &st, TreeNode* root, bool isNewTree, TreeNode* par) {
        if(root == NULL) return;
        if(st.find(root->val) == st.end()) { // root not to be deleted
            
            if(isNewTree) ans.push_back(root), isNewTree = false;
            
            helper(ans, st, root->left, false, root);
            helper(ans, st, root->right, false, root);
        }
        else { // root to be deleted
            if(par && par->left && par->left->val == root->val) par->left = nullptr;
            if(par && par->right && par->right->val == root->val) par->right = nullptr;
            
            helper(ans, st, root->left, true, root);
            helper(ans, st, root->right, true, root);
        }
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st; for(int& node: to_delete) st.insert(node);
        
        helper(ans, st, root, true, NULL);
        
        return ans;
    }
};