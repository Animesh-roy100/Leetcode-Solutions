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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> stk;
        int preIdx=0, postIdx=0;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode* curr = stk.top();

            if(curr->val == postorder[postIdx]) {
                stk.pop();
                postIdx++;
            } else {
                TreeNode *newNode = new TreeNode(preorder[preIdx]);
                preIdx++;

                if(curr->left == nullptr) {
                    curr->left = newNode;
                } else {
                    curr->right = newNode;
                }

                stk.push(newNode);
            }
        }

        return root;
    }
};