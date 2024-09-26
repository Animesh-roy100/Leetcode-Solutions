class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &it: bookings) {
            if(start < it.second and it.first < end) {
                return false;
            }
        }
        
        bookings.emplace_back(start, end);
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */