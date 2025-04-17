class Solution {
public:
    vector<int> parent, rank;

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv) {
            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
        
        vector<int> indegree(n+1, -1);
        int cycleEdge=-1, conflictEdge=-1;

        for(int i=0; i<n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if(indegree[v] != -1) {
                conflictEdge = i; // 2 parents
            } else {
                indegree[v] = i;
                int pu = findParent(u);
                int pv = findParent(v);

                if(pu == pv) {
                    cycleEdge = i; // Cycle detected
                } else {
                    UnionByRank(u, v);
                }
            }
        }

        // Handle Cases
        if(cycleEdge == -1 and conflictEdge == -1) {
            return {};
        } else if (conflictEdge == -1) {
            return edges[cycleEdge]; // only cycle exists
        } else if (cycleEdge == -1) {
            return edges[conflictEdge]; // only two parents exists
        } else {
            // Both conflict and cycle exists
            // Return first edge causing two parents
            int v = edges[conflictEdge][1];
            return edges[indegree[v]];
        }
    }
};