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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        // postorder(root, nums);
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;
        
        while(curr!=nullptr or !stk.empty()) {
            if(curr!=nullptr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peak = stk.top();
                if(peak->right != nullptr and peak->right != lastVisited) {
                    curr = peak->right;
                } else {
                    nums.push_back(peak->val);
                    lastVisited = stk.top();
                    stk.pop();
                }
            }
        } 
        return nums;
    }
    
//     void postorder(TreeNode* root, vector<int> &nums) {
//         if(root==nullptr) return;
        
//         postorder(root->left, nums);
//         postorder(root->right, nums);
//         nums.push_back(root->val);
//     }
};