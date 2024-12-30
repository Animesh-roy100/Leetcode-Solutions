class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int n=num.length();
        for(int i=0; i<n; i++) {
            while(!stk.empty() and k>0 and stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while(k-->0) stk.pop();
        if(stk.empty()) return "0";

        string ans="";
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        while(ans.length() != 0 and ans.back() == '0') {
            ans.pop_back();
        }
        if(ans=="") return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};