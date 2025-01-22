class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> vis;
    double queryAns;
public:
    bool dfs(string start, string end, double product) {
        if(adj.find(start) == adj.end() or adj.find(end) == adj.end()) {
            return false;
        }

        if(start == end and adj.find(start) != adj.end()) {
            queryAns = product;
            return true;
        }

        bool tempAns=false;
        vis[start] = true;

        for(int i=0; i<adj[start].size(); i++) {
            if(!vis[adj[start][i].first]) {
                tempAns = dfs(adj[start][i].first, end, product * adj[start][i].second);
                if(tempAns) {
                    break;
                }
            }
        }

        vis[start] = false;

        return tempAns;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size(), m=queries.size();
        vector<double> ans(m);

        for(int i=0; i<n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }

        for(int i=0; i<m; i++) {
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);
            if(pathFound) ans[i] = queryAns;
            else ans[i] = -1;
        }

        return ans;
    }
};