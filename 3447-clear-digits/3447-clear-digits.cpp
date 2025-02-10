class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;

        for(char c: s) {
            if(c >= 'a' and c <= 'z') {
                stk.push(c);
            } else {
                if(!stk.empty()) stk.pop();
            }
        }

        string ans;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};