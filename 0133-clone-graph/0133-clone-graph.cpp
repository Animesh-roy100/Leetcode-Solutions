/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr, Node* copy, unordered_map<Node*, Node*> &vis) {
        vis[curr] = copy;
        
        for(auto neighbor: curr->neighbors) {
            if(vis.find(neighbor) == vis.end()) {
                Node* newNode = new Node(neighbor->val);
                (copy->neighbors).push_back(newNode);
                dfs(neighbor, newNode, vis);
            } else {
                (copy->neighbors).push_back(vis[neighbor]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        unordered_map<Node*, Node*> vis;
        Node* copy = new Node(node->val);
        dfs(node, copy, vis);
        
        return copy;
    }
};