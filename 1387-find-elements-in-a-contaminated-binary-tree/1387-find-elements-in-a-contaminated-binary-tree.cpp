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
class FindElements {
private:
    TreeNode *curr;
    void decontaminate(TreeNode* root, int num) {
        if(root == nullptr) return;

        root->val = num;

        decontaminate(root->left, num * 2 + 1);
        decontaminate(root->right, num * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        decontaminate(root, 0);
        curr = root;
    }
    
    bool find(int target) {
        queue<TreeNode*> q;
        q.push(curr);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) continue;

            if(node->val == target) return true;

            q.push(node->left);
            q.push(node->right);
        }

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */