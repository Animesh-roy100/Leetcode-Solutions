class Solution {
private:
    vector<int> parent, rank;

    int findParent(int node) {
        if(node == parent[node]) return node;
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough edges to connect all nodes

        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;
        int extraEdges=0;

        // Union-Find for all connections
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            int pu = findParent(u);
            int pv = findParent(v);
            if(pu != pv) {
                unionByRank(u, v);
            } else {
                extraEdges++;
            }
        }

        // Count the number of connected components
        // unordered_set<int> st;
        // for(int i=0; i<n; i++) {
        //     int parent = findParent(i);
        //     if(st.find(parent) == st.end()) st.insert(parent);
        // }
        // int connComponents = st.size();

        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (findParent(i) == i) // Each unique parent represents one component
                connectedComponents++;
        }

        cout<<"connected components: "<<connectedComponents<<endl;
        cout<<"extra edges: "<<extraEdges<<endl;

        if(extraEdges >= connectedComponents-1) return connectedComponents-1;
        return -1;
    }
};