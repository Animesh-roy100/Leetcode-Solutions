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
    // i: index of string, depth: depth of string
    TreeNode* solve(string s, int &i, int depth, int n) { 
        if(i >= n) return nullptr;

        int j=i;
        while(j<n and s[j] == '-') {
            j++;
        }
        int dash = j-i;

        if(dash != depth) return nullptr;

        i += dash;
        int num=0;
        while(i<n and isdigit(s[i])) {
            num = num*10 + (s[i]-'0');
            i++;
        }

        cout<<num<<" ";

        TreeNode* curr = new TreeNode(num);
        curr->left = solve(s, i, depth+1, n);
        curr->right = solve(s, i, depth+1, n);

        return curr;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.length();
        int i=0;
        return solve(traversal, i, 0, n);
    }
};