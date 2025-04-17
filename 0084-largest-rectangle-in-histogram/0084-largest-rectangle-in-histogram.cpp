class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), maxArea=0, area=0;
        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() and heights[stk.top()] >= heights[i]) {
                int idx = stk.top();
                stk.pop();
                if(stk.empty()) area = heights[idx] * i;
                else area = heights[idx] * (i-stk.top()-1);

                maxArea = max(maxArea, area);
            }

            stk.push(i);
        }

        while(!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            if(stk.empty()) area = heights[idx] * n;
            else area = heights[idx]*(n-stk.top()-1);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};