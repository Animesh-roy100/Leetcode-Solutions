class Solution {
public:
    typedef pair<int, int> pii;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0}); // {dist, idx}

        vector<bool> visited(n, false);
        int minCost=0;

        while(!pq.empty()) {
            int dist = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(visited[idx]) continue;
            visited[idx] = true;

            minCost += dist;

            int x1 = points[idx][0];
            int y1 = points[idx][1];

            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    int x2 = points[i][0];
                    int y2 = points[i][1];

                    int newDist = abs(x1-x2) + abs(y1-y2);

                    pq.push({newDist, i});
                }
            }
        }

        return minCost;
    }
};