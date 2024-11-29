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
private:
     int cameraCount = 0;
     int NEEDS_CAMERA = 0;
     int HAS_CAMERA = 1;
     int COVERED = 2;
     int NOT_NEEDED = 3;
public:
    
    int solve(TreeNode *root) {
        if(root==nullptr) return NOT_NEEDED;
        
        if(root->left == nullptr and root->right == nullptr) {
            return NEEDS_CAMERA;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == NEEDS_CAMERA or right == NEEDS_CAMERA) {
            cameraCount++;
            return HAS_CAMERA;
        }
        
        if(left == HAS_CAMERA or right == HAS_CAMERA) {
            return COVERED;
        }

        return NEEDS_CAMERA;
    }
    
    int minCameraCover(TreeNode* root) {
        cameraCount = solve(root)==NEEDS_CAMERA ? cameraCount+1 : cameraCount;
        return cameraCount;
    }
};