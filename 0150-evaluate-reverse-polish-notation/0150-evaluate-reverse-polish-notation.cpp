class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> stk;
        for(int i=0; i<n; i++) {
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                if (tokens[i] == "+") stk.push(a+b);
                if (tokens[i] == "-") stk.push(b-a);
                if (tokens[i] == "*") stk.push(a*b);
                if (tokens[i] == "/") stk.push(b/a);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        
        return stk.top();
    }
};