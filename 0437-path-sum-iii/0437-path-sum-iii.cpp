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
    int count = 0;
    void solve(TreeNode *root, int target, long currSum) {
        if(root==nullptr) return;
        currSum += root->val;
        if(target==currSum) {
            count++;
        }
        solve(root->left, target, currSum);
        solve(root->right, target, currSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        
        solve(root, targetSum, 0);
        
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return count;
    }
};