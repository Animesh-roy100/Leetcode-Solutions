class SeatManager {
public:
    // vector<int> seat;

    priority_queue<int, vector<int>, greater<int>> pq;
    int seatNumber;
    
    SeatManager(int n) {
        // seat.resize(n, 0);
        // for(int i=0; i<n; i++) pq.push(i);
        seatNumber = 1;
    }
    
    int reserve() {
        // if(!pq.empty()) {
        //     int seatNum = pq.top();
        //     pq.pop();
        //     seat[seatNum] = 1;
        //     return seatNum+1;
        // }

        if(!pq.empty()) {
            int seatNum = pq.top();
            pq.pop();
            return seatNum;
        }

        return seatNumber++;
    }
    
    void unreserve(int seatNumber) {
        // seat[seatNumber-1] = 0;
        // pq.push(seatNumber-1);
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */