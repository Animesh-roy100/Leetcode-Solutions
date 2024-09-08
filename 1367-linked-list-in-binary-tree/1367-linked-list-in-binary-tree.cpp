/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr or head->val != root->val) return false;
        
        return solve(head->next, root->left) or solve(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        
        if(head->val == root->val) {
            if(solve(head->next, root->left) or solve(head->next, root->right)) {
                return true;
            }
        }
        
        if(isSubPath(head, root->left)) return true;
        if(isSubPath(head, root->right)) return true;
        
        return false;
    }
};