class RLEIterator {
public:
    queue<pair<int, int>> q; // Queue to store (count, value) pairs

    RLEIterator(vector<int>& encoding) {
        for (size_t i = 0; i < encoding.size(); i += 2) {
            int count = encoding[i];
            int value = encoding[i + 1];
            if (count > 0) {
                q.push({count, value});
            }
        }
    }
    
    int next(int n) {
        while (!q.empty() && n > 0) {
            auto& front = q.front();
            int count = front.first;
            int value = front.second;

            if (n <= count) {
                front.first -= n; // Reduce the count by n
                return value;    // Return the current value
            } else {
                n -= count; // Subtract the entire count
                q.pop();    // Remove the exhausted pair
            }
        }

        return -1; // If the queue is empty and n > 0, return -1
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */