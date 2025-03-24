class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n=meetings.size();
        vector<vector<int>> intervals;

        for(int i=0; i<n; i++) {
            if(intervals.empty() or meetings[i][0] > intervals.back()[1]) {
                intervals.push_back(meetings[i]);
            } else {
                intervals.back()[1] = max(intervals.back()[1], meetings[i][1]);
            }
        }

        for(auto interval: intervals) {
            days -= (interval[1] - interval[0] + 1);
        }

        return days;
    }
};