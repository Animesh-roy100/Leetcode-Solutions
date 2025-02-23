class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_map<int, int> serverReqCount;
        set<int> availableServers;

        // assign first k requests to k servers
        for(int i=0; i<k and i<arrival.size(); i++) {
            pq.push({arrival[i]+load[i], i});
            serverReqCount[i]++;
        }

        // Check of next requests
        for(int i=k; i<arrival.size(); i++) {
            // add available servers to a set
            while(!pq.empty() and arrival[i] >= pq.top().first) {
                availableServers.insert(pq.top().second);
                pq.pop();
            }

            if(availableServers.empty()) continue;

            // find the next available server in circular manner
            auto it = lower_bound(availableServers.begin(), availableServers.end(), i%k);
            if(it == availableServers.end()){
                it = availableServers.begin();
            } 

            // erase from available servers
            int assignedServer = *it;
            availableServers.erase(assignedServer);
            
            serverReqCount[assignedServer]++;
            pq.push({arrival[i]+load[i], assignedServer});
        }

        int maxReq=0;
        for(auto& [server, req]: serverReqCount) {
            maxReq = max(maxReq, req);
        }

        vector<int> res;
        for(auto& [server, req]: serverReqCount) {
            if(req == maxReq) {
                res.push_back(server);
            }
        }
        
        return res;
    }
};