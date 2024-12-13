class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, string s) {
        if(open==0 and close==0) {
            ans.push_back(s);
        }
        if(open > 0) {
            // s.push_back('(');
            solve(open-1, close, s + "(");
            // s.pop_back();
        }
        
        if(close > open) {
            // s.push_back(')');
            solve(open, close-1, s + ")");
            // s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n, n, s);
        return ans;
    }
};