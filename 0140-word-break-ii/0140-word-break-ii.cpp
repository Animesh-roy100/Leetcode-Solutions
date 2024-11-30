class Solution {
public:
    vector<string> ans;
    void solve(int i, string s, unordered_set<string> &set, string currentWord) {
        if(i==s.length()) {
            currentWord.pop_back();
            ans.push_back(currentWord);
            return;
        }
        
        string str="";
        for(int j=i; j<s.length(); j++) {
            str += s[j];
            if(set.find(str) != set.end()) {
                solve(j+1, s, set, currentWord + str + " ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;    
        for(string str: wordDict) set.insert(str);
    
        solve(0, s, set, "");
        
        return ans;
    }
};