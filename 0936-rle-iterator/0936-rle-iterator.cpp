class RLEIterator {
public:
    queue<pair<int, int>> q;
    RLEIterator(vector<int>& encoding) {
        for(int i=0; i<encoding.size(); i+=2) {
            if(encoding[i] > 0) {
                q.push({encoding[i], encoding[i+1]});
            }
        } 
    }
    
    int next(int n) {
        while(!q.empty() and n>0) {
            auto &front = q.front();
            int count = q.front().first;
            int val = q.front().second;

            if(n <= count) {
                front.first -= n;
                return val;
            } else {
                n -= count;
                q.pop();
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */