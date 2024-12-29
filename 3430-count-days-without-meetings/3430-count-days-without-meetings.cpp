class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        int n=meet.size();
        sort(meet.begin(), meet.end());
        vector<vector<int>> intervals;

        for(int i=0; i<n; i++) {
            if(intervals.empty() or meet[i][0] > intervals.back()[1]) {
                intervals.push_back({meet[i][0], meet[i][1]});
            } else {
                intervals.back()[1] = max(intervals.back()[1], meet[i][1]);
            }
        }

        for(auto it: intervals) {
            days -= (it[1]-it[0]+1);
        }

        return days;
    }
};