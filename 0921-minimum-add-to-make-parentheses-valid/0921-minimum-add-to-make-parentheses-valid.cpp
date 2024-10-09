class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(!st.empty() and c == ')' and st.top() == '(') st.pop();
            else st.push(c);
        }
        
        int ans=0;
        while(!st.empty()) {
            st.pop();
            ans++;
        }
        
        return ans;
    }
};