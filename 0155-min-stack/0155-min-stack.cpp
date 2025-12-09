class MinStack {
struct Node {
    int val;
    int minimum;
    Node* next;

    // contructor
    Node(int v) {
        val = v;
        minimum = v;
        next = nullptr;
    }
};

private:
Node *topNode; // top element of stack

public:
    MinStack() {
        topNode = nullptr;
    }
    
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode; // add the linked list before the newnode 
        if(topNode != nullptr) {
            newNode->minimum = min(newNode->val, topNode->minimum); // check and store the minimum element
        }
        topNode = newNode; // make the newNode top
    }
    
    void pop() {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    
    int top() {
        return topNode->val;
    }
    
    int getMin() {
        return topNode->minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */