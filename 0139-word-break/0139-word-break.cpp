class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &wordSet, vector<int> &dp) {
        if(idx == s.length()) return true;
        if(dp[idx] != -1) return dp[idx];

        string str="";
        for(int i=idx; i<s.length(); i++) {
            str += s[i];
            if(wordSet.find(str) != wordSet.end()) {
                if(solve(i+1, s, wordSet, dp)) return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n=s.length();
        vector<int> dp(n, -1);
        return solve(0, s, wordSet, dp);
    }
};