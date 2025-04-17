class Solution {
public:
    vector<int> parent, rank;

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv) {
            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        rank.resize(n+1, 0);

        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            if(findParent(u) == findParent(v)) return edge;
            unionByRank(u, v);
        }

        return {};
    }
};