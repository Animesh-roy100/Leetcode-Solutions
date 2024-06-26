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
    bool flag;
    
    pair<long, long> helper(TreeNode* root) {
        if(root == NULL) return {LONG_MAX, LONG_MIN};
        pair<long, long> left = helper(root->left);
        pair<long, long> right = helper(root->right);
        
        if(root->val <= left.second || root->val >= right.first) flag = false;
        
        return {min(left.first, (long)root->val), max((long)root->val, right.second)};
    }
    
    bool isValidBST(TreeNode* root) {
        flag = true;
        helper(root);
        return flag;
    }
};