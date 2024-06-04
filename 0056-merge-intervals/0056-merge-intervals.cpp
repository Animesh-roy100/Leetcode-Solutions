class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(auto &it: intervals) {
            if(ans.empty() or it[0]>ans.back()[1]) {
                ans.push_back({it[0], it[1]});
            }
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
        
        return ans;
    }
};