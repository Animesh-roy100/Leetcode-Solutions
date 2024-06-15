class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i=0; i<tasks.size(); i++) {
            count[tasks[i]-'A']++;
        }
        
        priority_queue<int> pq;
        for(int i=0; i<26; i++) {
            if(count[i]) pq.push(count[i]);
        }
        
        // cout<<pq.top();
        
        int time=0;
        while(!pq.empty()) {
            vector<int> remaining;
            int cycle = n+1;
            
            while(cycle and !pq.empty()) {
                int maxFreq = pq.top();
                pq.pop();
                if(maxFreq > 1) {
                    remaining.push_back(maxFreq-1);
                }
                time++;
                cycle--;
            }
            
            for(int i=0; i<remaining.size(); i++) {
                pq.push(remaining[i]);
            }
            
            if(pq.empty()) break;
            
            time += cycle;
        }
        return time;
    }
};