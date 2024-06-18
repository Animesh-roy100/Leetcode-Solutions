class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign='+';
        int temp=0;
        for(int i=0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                temp = temp*10 + (s[i]-'0');
            } 
            if ( !isdigit(s[i]) and s[i] != ' ' or i == s.length()-1) {
                // cout<<temp<<" ";
                if(sign == '+') {
                    stk.push(temp);
                }  else if(sign == '-') {
                    stk.push(-temp);
                } else {
                    int num = stk.top();
                    stk.pop();
                    
                    if(sign == '*') stk.push(num*temp);
                    if(sign == '/') stk.push(num/temp);
                }
                
                sign = s[i];
                temp = 0;
            }
        }
        
        int ans=0;
        while(!stk.empty()) {
            // cout<<stk.top()<<" ";
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};