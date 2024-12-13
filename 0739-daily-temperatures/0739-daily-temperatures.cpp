class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk;
        
        for(int i=0; i<n; i++) {
            while(!stk.empty() and temp[i] > stk.top().second) {
                int idx = stk.top().first;
                int tmp = stk.top().second;
                stk.pop();
                ans[idx] = i-idx;
            }
            stk.push({i, temp[i]});
        }
        
        return ans;
    }
};