class Solution {
public:
    typedef pair<long long, int> pli;


    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<int> availableRooms; // to check the availability
        for(int i=0; i<n; i++) availableRooms.insert(i); // every room is available at first

        priority_queue<pli, vector<pli>, greater<pli>> pq; // {time, meetingRoom}
        vector<int> roomCount(n, 0); // to count number of meetings held by the room

        sort(meetings.begin(), meetings.end()); // sort the meetings

        for(int i=0; i<meetings.size(); i++) {
            long long startTime = meetings[i][0];
            long long endTime = meetings[i][1];

            while(!pq.empty() and startTime >= pq.top().first) {
                availableRooms.insert(pq.top().second);
                pq.pop();
            }

            if(!availableRooms.empty()) {
                auto room = *availableRooms.begin();
                availableRooms.erase(room);
                roomCount[room]++;
                pq.push({endTime, room});
            } else {
                auto [time, room] = pq.top();
                pq.pop();
                pq.push({time + (endTime-startTime), room});
                roomCount[room]++;
            }
        }
        
        int maxCount=0, room=0;
        for(int i=0; i<n; i++) {
            if(maxCount < roomCount[i]) {
                maxCount = roomCount[i];
                room = i;
            }
        }

        return room;
    }
};