class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        sort(points.begin(), points.end());
        // int count=0, lastEle=INT_MAX;
        
        for (auto &it: points) {
            if(ans.empty() || it[0] > ans.back()[1]) {
                ans.push_back({it[0], it[1]});
            }
            ans.back()[1] = min(ans.back()[1], it[1]);
        }
        return ans.size();
    }
};