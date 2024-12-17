class Solution {
public:
    bool solve(int idx, string s, unordered_set<string> &st, vector<int> &dp) {	
        if(idx == s.length()) return true;
	    if(dp[idx] != -1) return dp[idx];
        string str="";
        for(int i=idx; i<s.length(); i++) {
            str.push_back(s[i]);
            if(st.find(str) != st.end()) {
                if(solve(i+1, s, st, dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[idx] = false;
    } 
    
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st;
        for(auto str: dict) st.insert(str);
        int n=s.length();
        vector<int> dp(n, -1);
        return solve(0, s, st, dp);
    }
};