class LRUCache {
private: 
    class Node {
        public:
            int key;
        int value;
        Node *next;
        Node *prev;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    int cap;
    unordered_map<int, Node*> m;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    void removeNode(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void addNode(Node *node) {
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        Node *temp = m[key];
        int res = temp->value;
        m.erase(key);
        removeNode(temp);
        addNode(temp);
        m[key] = head->next;
        
        return res;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node *temp = m[key];
            m.erase(key);
            removeNode(temp);
        }
        
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */