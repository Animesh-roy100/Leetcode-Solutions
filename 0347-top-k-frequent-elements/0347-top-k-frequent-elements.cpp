class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int n=nums.size();
        for(int i=0; i<n; i++) {
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &it: umap) {
            pq.push({-it.second, it.first});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};