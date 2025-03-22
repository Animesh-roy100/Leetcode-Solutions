class Solution {
private:
    vector<int> parent, rank;

public:
    int findParent(int val) {
        if(parent[val] == val) return val;

        return parent[val] = findParent(parent[val]);
    }
    
    void UnionByRank(int u, int v) {
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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
        rank.resize(n, 0);

        for(auto &edge: edges) {
            UnionByRank(edge[0], edge[1]);
        }

        vector<int> componentSize(n, 0);
        vector<int> componentEdges(n, 0);

        for(int i=0; i<n; i++) {
            componentSize[findParent(i)]++;
        }

        for(auto &edge: edges) {
            componentEdges[findParent(edge[0])]++;
        }

        int count=0;
        for(int i=0; i<n; i++) {
            if(findParent(i) == i) {
                int size = (long long)componentSize[i] * (componentSize[i] - 1)/2;
                if(componentEdges[i] == size) count++;
            }
        }

        return count;
    }
};