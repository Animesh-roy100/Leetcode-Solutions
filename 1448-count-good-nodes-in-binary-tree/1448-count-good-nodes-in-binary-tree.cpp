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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int ans=0;
        while(!q.empty()) {
                TreeNode *curr = q.front().first;
                int maxEle = q.front().second;
                q.pop();
                
                if(curr->val >= maxEle){
                    ans++;
                }
                
                if(curr->left) q.push({curr->left, max(maxEle, curr->val)});
                if(curr->right) q.push({curr->right, max(maxEle, curr->val)});
        }
        
        return ans;
    }
};