class LRUCache {
private:
    class Node{
        public:
            int key;
        int value;
        Node *prev;
        Node *next;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    int cap;
    unordered_map<int, Node*> m;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    void deleteNode(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void addNode(Node *node) {
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        Node *resNode = m[key];
        int res = resNode->value;
        m.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        m[key] = head->next;
        
        return res;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
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