class Solution {
public:
    vector<string> nextOptions(string str) {
        vector<string> options;
        for(int i=0; i<4; i++) {
            char ch = str[i];

            str[i] = (ch == '9') ? '0' : ch+1;
            options.push_back(str);

            str[i] = (ch == '0') ? '9' : ch-1;
            options.push_back(str);

            str[i] = ch;
        }

        return options;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis.insert("0000");

        while(!q.empty()) {
            int size = q.size();
            while(size-->0) {
                string str = q.front().first;
                int turns = q.front().second;
                q.pop();
                if(str == target) return turns;
                if(deadendSet.find(str) != deadendSet.end()) continue;
                for(auto option: nextOptions(str)) {
                    if(vis.find(option) == vis.end()) {
                        q.push({option, turns+1});
                        vis.insert(option);
                    }
                }
            }
        }

        return -1;
    }
};