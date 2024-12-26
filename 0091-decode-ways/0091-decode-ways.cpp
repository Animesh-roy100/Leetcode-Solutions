class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int ways = solve(i+1, s, dp);
        if(i < s.length()-1) {
            string str="";
            str.push_back(s[i]);
            str.push_back(s[i+1]);
            if(str >= "1" and str <= "26") {
                ways += solve(i+2, s, dp);
            }
        }
        
        return dp[i] = ways;
    }
    
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};