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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            root = new TreeNode(val);   
            return root;
        }
        
        TreeNode* curr = root;
        if(curr->val > val) {
            root->left = insertIntoBST(curr->left, val);
        }
        if(curr->val < val) {
            root->right = insertIntoBST(curr->right, val);
        }
        
        return root;
    }
};