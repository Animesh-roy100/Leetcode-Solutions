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
    // left =0, right = 1
    int maxPath=0;
    void dfs(int dir, TreeNode* root, int currPath) {
        if(root==nullptr) return;
        maxPath = max(maxPath, currPath);
        if(dir) {
            dfs(!dir, root->left, 1 + currPath);
            dfs(dir, root->right, 1);
        }
        else {
            dfs(!dir, root->right, 1 + currPath);
            dfs(dir, root->left, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(0, root->left, 1); // go to the left
        dfs(1, root->right, 1); // move to the right
        return maxPath;
    }
};