/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        // ans.push_back(root->val);
        // preOrder(root, ans);
        
        stack<Node*> stk;
        stk.push(root);
        
        while(!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            
            ans.push_back(curr->val);
            
            for(int i=curr->children.size()-1; i>=0; i--) {
                stk.push(curr->children[i]);
            }
        }
        
        return ans;
    }
    
//     void preOrder(Node* root, vector<int> &ans) {
//         if(root==NULL) return;
        
//         for(auto it: root->children) {
//             ans.push_back(it->val);
//             preOrder(it, ans);
//         }
//     }
};