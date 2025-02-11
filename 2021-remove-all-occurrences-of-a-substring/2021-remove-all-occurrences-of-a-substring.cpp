class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        int n=s.length(), m=part.length();
        if(n<m) return s;

        stack<char> stk;

        for(char c: s) {
            stk.push(c);
            if(stk.size() >= part.size() and stk.top() == part.back()) {
                string temp="";
                int size=part.size();
                while(size--) {
                    temp += stk.top();
                    stk.pop();
                }
                reverse(temp.begin(), temp.end());
                if(temp != part) {
                    for(char c: temp) {
                        stk.push(c);
                    }
                }
            }
        }

        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};