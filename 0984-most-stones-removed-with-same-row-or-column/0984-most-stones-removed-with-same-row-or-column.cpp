class Solution {
private:
    vector<int> parent, rank;

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]); // path compression
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;

        for(int u=0; u<n-1; u++) {
            for(int v=u+1; v<n; v++) {
                if(stones[u][0] == stones[v][0] or stones[u][1] == stones[v][1]) {
                    unionByRank(u, v);
                }
            }
        }

        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(findParent(i));
        }

        return n-st.size();
    }
};