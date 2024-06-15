class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        
        for(int i=0; i<words.size(); i++) {
            hashMap[words[i]]++;
        }
        
        priority_queue<pair<int, string>> pq;
        for(auto &it: hashMap) {
            pq.push({-it.second, it.first});
            if(pq.size()>k) pq.pop();
        } 
        
        vector<string> ans;
        while(k--) {
            // cout<<pq.top().second;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};