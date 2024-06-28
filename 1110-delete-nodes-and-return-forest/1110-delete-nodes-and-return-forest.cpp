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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set;
        for(int &node: to_delete) set.insert(node);
        
        vector<TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        if(set.find(root->val) == set.end()) {
            ans.push_back(root);
        } 
        
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
            if(curr->left and set.find(curr->left->val) != set.end()) {
                curr->left = nullptr;
            }
            if(curr->right and set.find(curr->right->val) != set.end()) {
                curr->right = nullptr;
            }
            
            if(set.find(curr->val) != set.end()) {
                if(curr->left) ans.push_back(curr->left);
                if(curr->right) ans.push_back(curr->right);
            }
        }
        
        return ans;
    }
};