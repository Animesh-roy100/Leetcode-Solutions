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
    
    vector<TreeNode*> solve(int n) {
        if(n%2 == 0) return {}; // n is even
        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        vector<TreeNode*> res;

        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(n-i-1);

            for(auto &l: left) {
                for(auto &r: right) {
                    TreeNode* root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};