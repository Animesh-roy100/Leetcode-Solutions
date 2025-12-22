class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> ans;

        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        visited[0][0] = true;
        int level = 0;

        while(!q.empty()) {
            int size=q.size();
            vector<int> temp;
            for(int i=0; i<size; i++) {
                auto [x, y] = q.front();
                q.pop();

                temp.push_back(mat[x][y]);

                if(x+1 < m and !visited[x+1][y]) {
                    q.push({x+1, y});
                    visited[x+1][y] = true;
                }

                if(y+1 < n and !visited[x][y+1]) {
                    q.push({x, y+1});
                    visited[x][y+1] = true;
                }
            }

            if(level%2 != 0) {
                reverse(temp.begin(), temp.end());
            }

            ans.insert(ans.end(), temp.begin(), temp.end());
            level++;
        }

        return ans;
    }
};