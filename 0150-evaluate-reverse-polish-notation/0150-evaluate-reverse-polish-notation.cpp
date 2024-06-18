class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> stk;
        for(int i=0; i<n; i++) {
            if(tokens[i] == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int sum = a+b;
                stk.push(sum);
            } else if (tokens[i] == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int diff = b-a;
                stk.push(diff);
            } else if (tokens[i] == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int prod = a*b;
                stk.push(prod);
            } else if (tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int divide = b/a;
                stk.push(divide);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        
        return stk.top();
    }
};