class Solution {
private:
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
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int n=isConn.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) {
                if(isConn[i][j] == 1) {
                    unionByRank(i, j);
                }
            }
        }

        int count=0;
        for(int i=0; i<n; i++) {
            if(findParent(i) == i) {
                count++;
            }
        }

        return count;
    }
};