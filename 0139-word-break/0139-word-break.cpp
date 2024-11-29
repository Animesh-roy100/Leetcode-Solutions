class Solution {
public:
    bool solve(int i, string s, unordered_set<string> set, vector<int> &dp) {
        if(i==s.length()) return true;
        if(dp[i] != -1) return dp[i];
        string str="";
        for(int j=i; j<s.length(); j++) {
            str += s[j];
            cout<<str<<endl;
            if(set.find(str) != set.end()) {
                if(solve(j+1, s, set, dp)) {
                    return dp[i] = true;
                }
            }
        }
        
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> set;
        for(string word: wordDict) set.insert(word);
        vector<int> dp(n, -1);
        return solve(0, s, set, dp);
    }
};