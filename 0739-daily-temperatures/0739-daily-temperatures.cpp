class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n);
        stack<int> stk;
        
        for(int i=0; i<n; i++) {
            while(!stk.empty() and temp[stk.top()] < temp[i]) {
                int prevIndex = stk.top();
                ans[prevIndex] = i-prevIndex;
                stk.pop();
            }
            stk.push(i);
        }
        
        return ans;
    }
};