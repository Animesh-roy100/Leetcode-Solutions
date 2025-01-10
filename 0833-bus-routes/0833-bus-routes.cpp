class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();

        unordered_map<int, vector<int>> busStopsToIds;
        for(int i=0; i<n; i++){
            for(int j=0; j<routes[i].size(); j++) {
                busStopsToIds[routes[i][j]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push({source, 0}); // route, stops

        vector<bool> busVis(n, false);
        unordered_map<int, bool> busStopVis;
        busStopVis[source] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--) {
                int currBusStop = q.front().first;
                int busTravelled = q.front().second;
                q.pop();
                
                if(currBusStop == target) return busTravelled;

                for(auto bus: busStopsToIds[currBusStop]) {
                    if(busVis[bus]) continue;
                    busVis[bus] = true;
                    for(auto busStop: routes[bus]) {
                        if(busStopVis[busStop]) continue;
                        busStopVis[busStop] = true;
                        q.push({busStop, busTravelled+1});
                    }
                }
            }
        }
        return -1;
    }
};