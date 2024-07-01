class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        // sort(bombs.begin(), bombs.end());
        
        unordered_map<int, vector<int>> umap;
        
        for(int i=0; i<n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            vector<int> adj;
            
            for(int j=0; j<n; j++) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                // int r2 = bombs[j][2];
                
                if(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2) <= 1LL*r1*r1) {
                    adj.push_back(j);
                }
            }
            
            umap[i] = adj;
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++) {
            queue<int> q;
            q.push(i);
            unordered_set<int> st;
            st.insert(i);
            
            while(!q.empty()) {
                int index = q.front();
                q.pop();
                
                for(auto &node: umap[index]) {
                    if(st.find(node) == st.end()) {
                        q.push(node);
                        st.insert(node);
                    }
                }
            }
            // cout<<st.size()<<" ";
            // if(ans < st.size()) {
            //     ans = st.size();
            // }
            int size = st.size();
            ans = max(ans, size);
        }
        
        return ans;
    }
};