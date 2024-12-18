class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> v(26, 0);
        for(auto task: tasks) {
            v[task-'A']++;
        }
        for(int i=0; i<26; i++) {
            if(v[i]>0) pq.push(v[i]);
        }
        
        int time=0;
        while(!pq.empty()) {
            vector<int> remaining;
            int cycle = n+1;
            while(!pq.empty() and cycle) {
                int maxTask = pq.top();
                pq.pop();
                if(maxTask>1) remaining.push_back(maxTask-1);
                cycle--;
                time++;
            }
            
            for(int i: remaining) pq.push(i);
            if(pq.empty()) break;
            
            time += cycle;
        }
        
        return time;
    }
};