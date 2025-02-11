class MyCircularQueue {
public:
    vector<int> queue;
    int qSize;
    int k;
    int pointer;

    MyCircularQueue(int _k) {
        queue.resize(_k, -1);
        qSize=0;
        k=_k;
        pointer=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        queue[(pointer + qSize) % k] = value;
        qSize++;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        pointer = (pointer + 1) % k;
        qSize--;

        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return queue[pointer];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return queue[(qSize + pointer - 1) % k];
    }
    
    bool isEmpty() {
        return qSize == 0;
    }
    
    bool isFull() {
        return qSize == k;
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