class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        
        for(int i=0; i<n; i++) {
            while(!stk.empty() and temp[i] > temp[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                ans[idx] = i-idx;
            }
            stk.push(i);
        }
        
        return ans;
    }
};