class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> pq;
        int currentTime = 0;

        for(int i=0; i<courses.size(); i++) {
            int duration = courses[i][0];
            int lastDay = courses[i][1];

            if(currentTime + duration <= lastDay) {
                currentTime += duration;
                pq.push(duration);
            } else if (!pq.empty() and pq.top() > duration) {
                currentTime = currentTime - pq.top() + duration;
                pq.pop();
                pq.push(duration);
            }
        }

        return pq.size();
    }
};