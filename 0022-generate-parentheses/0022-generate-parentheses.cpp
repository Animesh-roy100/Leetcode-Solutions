class Solution {
public:
    vector<string> ans;
    void solve(string &s, int count, int open, int close) {
        if(count<0) return;
        if(open==0 and close==0) {
            ans.push_back(s);
            return;
        }
        
        if(open > 0) {
            s.push_back('(');
            solve(s, count+1, open-1, close);
            s.pop_back();
        } 
        
        if(close > 0){
            s.push_back(')');
            solve(s, count-1, open, close-1);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s, 0, n, n);
        return ans;
    }
};