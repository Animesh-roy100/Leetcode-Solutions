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
    int check(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh = check(root->left);
        int rh = check(root->right);
        
        if(lh==-1 or rh==-1) return -1;
        if(abs(lh-rh) > 1) return -1;
        
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        
        int height = check(root);
        
        if(height == -1) return false;
        
        return true;
    }
};