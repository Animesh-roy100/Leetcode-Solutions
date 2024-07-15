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
public:
    TreeNode* buildBST(vector<int> &v, int l, int r) {
        if(l>r) return nullptr;
        
        int mid = l+(r-l)/2;
        
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = buildBST(v, l, mid-1);
        root->right = buildBST(v, mid+1, r);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* curr=head;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        return buildBST(v, 0, v.size()-1);
    }
};