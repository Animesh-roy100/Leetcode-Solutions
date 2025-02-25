class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++) {
            vector<int> curr = intervals[i];

            if(curr[1] < newInterval[0]) {
                if(ans.empty() or ans.back()[1] < curr[0]) {
                    ans.push_back(curr);
                } else {
                    ans.back()[1] = max(ans.back()[1], curr[1]);
                }
            } else if(curr[0] > newInterval[1]) {
                // the new interval's range is before the other
                ans.push_back(newInterval);
                newInterval = curr;
            } else {
                // the new interval is in the range of the other interval
                newInterval[0] = min(newInterval[0], curr[0]);
                newInterval[1] = max(newInterval[1], curr[1]);
            }
        }
        ans.push_back(newInterval);
        
        return ans;
    }
};