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
    vector<int> postorder(Node* root) {
        vector<int> nums;
        if(root==NULL) return nums;
        // postOrder(root, nums);
        // nums.push_back(root->val);
        
        
        stack<Node*> stk({root});
        
        while(!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            
            nums.push_back(curr->val);
            
            for(auto it: curr->children) {
                stk.push(it);
            }
        }
        
        reverse(nums.begin(), nums.end());
        return nums;
    }
    
//     void postOrder(Node* root, vector<int> &nums) {
//         if(root==NULL) return;
        
//         for(auto it: root->children) {
//             postOrder(it, nums);
//             nums.push_back(it->val);
//         }
//     }
};