class Solution {
public:
    bool solve(int i, string s, unordered_set<string> &set, vector<int> &dp) {
        if(i==s.length()) return true;
        if(dp[i] != -1) return dp[i];
        string str = "";
        for(int j=i; j<s.length(); j++) {
            str += s[j];
            if(set.find(str) != set.end()) {
                if(solve(j+1, s, set, dp)) {
                    return dp[i] = true;
                }
            }
        }
        
        return dp[i] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        vector<string> ans;
        for(string word: words) {
            set.erase(word);
            int n=word.size();
            vector<int> dp(n, -1);
            if(solve(0, word, set, dp)) {
                ans.push_back(word);
            }  
            set.insert(word);
        }
        
        return ans;
    }
};