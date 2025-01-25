class Solution {
public:
    void dfs(unordered_map<string, multiset<string>> &graph, vector<string> &ans, string start) {
        while(!graph[start].empty()) {
            string ticket=*graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(graph, ans, ticket);
        }

        ans.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for(auto &ticket: tickets) graph[ticket[0]].insert(ticket[1]);

        vector<string> ans;
        dfs(graph, ans, "JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};