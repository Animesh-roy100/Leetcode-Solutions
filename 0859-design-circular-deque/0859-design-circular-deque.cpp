class MyCircularDeque {
public:
    vector<int> deq;
    int k;
    int qSize;
    int pointer;

    MyCircularDeque(int _k) {
        k = _k;
        qSize=0;
        pointer=0;
        deq.resize(_k, -1);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        pointer = (pointer - 1 + k) % k;
        deq[pointer] = value;
        qSize++;

        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        deq[(pointer + qSize) % k] = value;
        qSize++;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        deq[pointer] = -1;
        pointer = (pointer + 1) % k;
        qSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        deq[(pointer + qSize -1) % k] = -1;
        qSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deq[pointer];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deq[(pointer + qSize -1) % k];
    }
    
    bool isEmpty() {
        return qSize == 0;
    }
    
    bool isFull() {
        return qSize == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */