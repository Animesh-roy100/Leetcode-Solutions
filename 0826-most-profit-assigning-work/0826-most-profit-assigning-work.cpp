class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<profit.size(); i++) {
            pq.push({profit[i], difficulty[i]});
        }
        cout<<pq.top().second;
        
        sort(worker.begin(), worker.end());
        int ans=0, i=worker.size()-1;
        while(i>=0 and !pq.empty()) {
            // cout<<pq.top().first<<" ";
            if(worker[i] < pq.top().second) {
                // cout<<pq.size()<<" ";
                pq.pop();
            } else {
                // cout<<pq.top().second<<" ";
                ans += pq.top().first;
                i--;
                // cout<<ans<<" ";
            }
        }
        
        return ans;
    }
};