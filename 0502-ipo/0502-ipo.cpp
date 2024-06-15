class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        
        int n=profits.size();
        for(int i=0; i<n; i++) {
            minHeap.push({capital[i], profits[i]});
        }
        
        // cout<<minHeap.top().second;
        
        priority_queue<int> maxHeap;
        while(k--) {
            while(!minHeap.empty() and minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if(maxHeap.empty()) {
                return w;
            }
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};