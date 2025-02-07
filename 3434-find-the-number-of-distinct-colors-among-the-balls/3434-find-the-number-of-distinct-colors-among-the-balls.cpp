class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> ballToColor, colorCount; 
        for(auto query: queries) {
            int currBall = query[0];
            int currColor = query[1];

            if(ballToColor.find(currBall) != ballToColor.end()) {
                colorCount[ballToColor[currBall]]--;
                if(colorCount[ballToColor[currBall]] == 0) colorCount.erase(ballToColor[currBall]);
            }

            ballToColor[currBall] = currColor;
            colorCount[currColor]++;

            ans.push_back(colorCount.size());
        }

        return ans;
    }
};