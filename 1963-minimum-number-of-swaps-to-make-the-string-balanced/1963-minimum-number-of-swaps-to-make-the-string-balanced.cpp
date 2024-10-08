class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char c: s) {
            if(!st.empty() and c == ']' and st.top() == '[') st.pop();
            else st.push(c);
        }
        
        int open=0;
        while(!st.empty()) {
            if(st.top() == '[') open++;
            st.pop();
        }
        
        return (open+1)/2;
    }
};