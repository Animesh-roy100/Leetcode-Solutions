class CustomStack {
public:
    vector<int> v;
    int max;
    CustomStack(int maxSize) {
        max=maxSize;
    }
    
    void push(int x) {
        if(v.size() < max) {
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.size() == 0) return -1;
        int ele = v[v.size()-1];
        v.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        if(v.size() > k) {
            for(int i=0; i<k; i++) {
                v[i] += val;
            }
        } else {
            for(int i=0; i<v.size(); i++) {
                v[i] += val;
            }
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */