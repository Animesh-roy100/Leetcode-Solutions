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
    unordered_map<TreeNode*, int> um;
    int solve(TreeNode* root) {
        if(um.find(root) != um.end()) return um[root];
        
        if(root==nullptr) return 0;
        int leftleft=0, leftright=0, rightleft=0, rightright=0;
        if(root->left != nullptr) {
            leftleft = solve(root->left->left);
            leftright = solve(root->left->right);
        } 
        if(root->right != nullptr) {
            rightleft = solve(root->right->left);
            rightright = solve(root->right->right);
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int includeRoot = root->val + leftleft + leftright + rightleft + rightright;
        int excludeRoot = left + right;
        
        um[root] = max(includeRoot, excludeRoot);
        
        return um[root];
    }
    
    int rob(TreeNode* root) {
        int res=0;
        return solve(root);
    }
};