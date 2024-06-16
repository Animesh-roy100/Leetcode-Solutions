class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        
        unordered_map<char,int> umap;
        for(int i=0; i<s.length(); i++) {
            umap[s[i]]++;
        }
        
        for(auto &it: umap) {
            // cout<<it.first;
            pq.push({it.second, it.first});
        }
        
        string ans="";
        
        while(!pq.empty()) {
            int freq = pq.top().first;
            while(freq--) {
                // cout<<pq.top().second;
                ans += pq.top().second;
            }
            pq.pop();
        }
        
        return ans;
    }
};