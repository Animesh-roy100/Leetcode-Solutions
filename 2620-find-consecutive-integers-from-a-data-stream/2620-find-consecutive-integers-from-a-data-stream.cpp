class DataStream {
private:
    // vector<int> stream; // getting TLE
    // More memory efficient would be not to store the stream but 
    // to store the consecutive "value" count
    int cons, val;
    int count;
public:
    DataStream(int value, int k) {
        cons = k;
        val = value;
        count = 0;
    }
    
    bool consec(int num) {
        // stream.push_back(num);
        // int n=stream.size();
        // if(n < cons) return false;

        // for(int i=n-1; i>=n-cons; i--) {
        //     if(stream[i] != val) return false;
        // }

        if(num == val) count++;
        else count = 0;

        return count >= cons;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */