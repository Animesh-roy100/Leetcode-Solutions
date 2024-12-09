class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto it: intervals) {
            if(ans.empty() or it[0] > ans.back()[1]) {
                ans.push_back({it[0], it[1]});
            } else {
                ans.back()[1] = max(ans.back()[1], it[1]); 
            }
        }
        
        return ans;
    }
};