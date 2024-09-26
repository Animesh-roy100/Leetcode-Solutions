class Solution {
public:
    static bool compare(string &a, string &b) {
        return a.size() < b.size();    
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        
        // for(auto word: words) {
        //     cout<<word<<" ";    
        // }
        
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1; 
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isPredecessor(words[j], words[i]) and dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if(ans < dp[i]) ans = dp[i];
        }
        
        return ans;
    }
    
    bool isPredecessor(string s1, string s2) {
        if(s2.size() != s1.size()+1) return false;
        int i=0, j=0;
        while(j<s2.size()) {
            if(i<s1.size() and s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == s1.size();
    }
};