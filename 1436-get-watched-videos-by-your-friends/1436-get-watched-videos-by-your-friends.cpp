class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> videos;

        queue<pair<int, int>> q;
        q.push({id, 0});
        unordered_map<int, bool> vis;
        vis[id]=true;

        while(!q.empty()) {
            int node = q.front().first;
            int currLevel = q.front().second;
            q.pop();

            if(currLevel == level) {
                for(auto video: watchedVideos[node]) {
                    videos[video]++;
                }
            }

            for(auto newNode: friends[node]) {
                if(!vis[newNode]) {
                    vis[newNode] = true;
                    q.push({newNode, currLevel+1});
                }
            }
        }

        vector<pair<int, string>> temp;
        for(auto it: videos) {
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end());

        vector<string> ans;
        for(auto it: temp){
            ans.push_back(it.second);
        }

        return ans;
    }
};