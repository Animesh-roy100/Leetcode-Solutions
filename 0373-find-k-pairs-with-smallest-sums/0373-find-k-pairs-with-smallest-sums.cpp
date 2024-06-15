class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n=nums1.size(), m=nums2.size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push({nums1[i]+nums2[0], {i, 0}});
        }
        
        while(k-- and !pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            ans.push_back({nums1[x], nums2[y]});
            
            if(y+1<m) {
               pq.push({nums1[x]+nums2[y+1], {x, y+1}});
            }
        }
        
        return ans;
    }
};