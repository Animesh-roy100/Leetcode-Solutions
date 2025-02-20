class MedianFinder {
private:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();

        if(minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() > minh.size()) return maxh.top();
        return (maxh.top() + minh.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */