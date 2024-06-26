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
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr) return root;
        vector<int> nums;
        inorder(root, nums);
        return buildBST(nums, 0, nums.size()-1);
    }
    
    void inorder(TreeNode* root, vector<int> &nums) {
        if(root==nullptr) return;
        
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    TreeNode* buildBST(vector<int> &nums, int low, int high) {
        if(high<low) return nullptr;
        
        int mid = (high+low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        if(high==low) return root;
        
        root->left=buildBST(nums, low, mid-1);
        root->right=buildBST(nums, mid+1, high);
        
        return root;
    }
};