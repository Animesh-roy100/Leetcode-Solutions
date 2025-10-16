class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s) {
            if(c == '(' or c == '[' or c == '{') stk.push(c);
            else {
                if(c == ')') {
                    if(!stk.empty() and stk.top() == '(') {
                        stk.pop();
                        continue;
                    } else return false;
                }
                if(c == '}') {
                    if(!stk.empty() and stk.top() == '{') {
                        stk.pop();
                        continue;
                    } else return false;
                }
                if(c == ']') {
                    if(!stk.empty() and stk.top() == '[') {
                        stk.pop();
                        continue;
                    } else return false;
                }
            }
        }
        return stk.empty();
    }
};