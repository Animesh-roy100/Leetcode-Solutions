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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorder(root, ans);
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while(curr!=NULL or !stk.empty()) {
            while(curr!=NULL) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
        return ans;
    }
    
    // void inorder(TreeNode* root, vector<int> &ans) {
    //     if(root==nullptr) return;
    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }
};