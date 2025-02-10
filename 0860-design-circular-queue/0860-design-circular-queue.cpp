class MyCircularQueue {
public:
    vector<int> deq;
    int qSize;
    int index;
    int size;

    MyCircularQueue(int k) {
        size = k;
        deq.resize(k, -1);
        index = 0;
        qSize=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        deq[(index + qSize) % size] = value;
        qSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        index = (index + 1) % size;
        qSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return deq[index];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return deq[(index + qSize - 1) % size];
    }
    
    bool isEmpty() {
        return !qSize;
    }
    
    bool isFull() {
        return qSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */