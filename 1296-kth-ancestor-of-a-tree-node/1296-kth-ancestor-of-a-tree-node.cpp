class TreeAncestor {
private: 
    vector<vector<int>> anc;
public:
    TreeAncestor(int n, vector<int>& parent) {
        anc.resize(n, vector<int> (30, -1));

        for(int i=0; i<n; i++) anc[i][0] = parent[i];

        for(int j=1; j<30; j++) {
            for(int i=0; i<n; i++) {
                if(anc[i][j-1] != -1) {
                    anc[i][j] = anc[anc[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;

        for(int i=0; i<30; i++) {
            if(k & (1<<i)) {
                ans = anc[ans][i];
                if(ans == -1) return -1;
            }
        }

        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */