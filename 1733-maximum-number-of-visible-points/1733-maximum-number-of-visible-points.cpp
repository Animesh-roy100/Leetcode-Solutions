class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles; // for every point calculate the angle
        int x = location[0], y = location[1];
        int same = 0; // count points that are at the same location as the observer

        for (auto& point : points) {
            int dx = point[0] - x;
            int dy = point[1] - y;
            if (dx == 0 && dy == 0) {
                same++; // same location as the observer
                continue;
            }
            double theta = atan2(dy, dx) * 180 / M_PI; // calculate angle in degrees
            if (theta < 0) theta += 360; // convert to [0, 360) range
            angles.push_back(theta);
        }

        sort(angles.begin(), angles.end());

        // Duplicate the angles to handle circular nature (e.g., 359° and 1° are close)
        int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360);
        }

        int ans=0, l=0;

        for(int r=0; r<angles.size(); r++) {
            while(angles[r]-angles[l] > angle) {
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans + same;
    }
};