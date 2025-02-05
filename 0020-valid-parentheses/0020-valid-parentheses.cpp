class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s) {
            if(c == '(' or c == '{' or c == '[') {
                stk.push(c);
            } else if(c == ')') {
                if(!stk.empty() and stk.top() == '(') {
                    stk.pop();
                } else return false;
            } else if(c == '}') {
                if(!stk.empty() and stk.top() == '{') {
                    stk.pop();
                } else return false;
            } else if(c == ']') {
                if(!stk.empty() and stk.top() == '[') {
                    stk.pop();
                } else return false;
            }
        }

        return stk.size() == 0;
    }
};