class Solution {
public:
    typedef pair<int, int> pii;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> vis(n, false);

        pq.push({0, 0});

        int minDist=0;

        while(!pq.empty()) {
            int dist = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(vis[idx]) continue;
            vis[idx] = true;
            minDist += dist;

            int x1 = points[idx][0];
            int y1 = points[idx][1];

            for(int i=0; i<n; i++) {
                if(!vis[i]) {
                    int x2 = points[i][0];
                    int y2 = points[i][1];

                    int newDist = abs(x1-x2) + abs(y1-y2);

                    pq.push({newDist, i});
                }
            }
        }

        return minDist;
    }
};