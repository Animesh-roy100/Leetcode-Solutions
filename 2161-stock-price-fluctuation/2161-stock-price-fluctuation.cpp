class StockPrice {
private:
unordered_map<int, int> time_to_price;
int maxTime=0;
multiset<int> allVals;

public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(time_to_price.find(timestamp) != time_to_price.end()) {
            auto oldVal = allVals.find(time_to_price[timestamp]);
            allVals.erase(oldVal);
        }

        maxTime = max(maxTime, timestamp);
        time_to_price[timestamp] = price;
        allVals.insert(price);
    }
    
    int current() {
        return time_to_price[maxTime];
    }
    
    int maximum() {
        return *allVals.rbegin();
    }
    
    int minimum() {
        return *allVals.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */