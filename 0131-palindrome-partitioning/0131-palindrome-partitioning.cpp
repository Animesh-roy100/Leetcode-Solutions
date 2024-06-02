class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        while(start<end) {
            if (s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    void backtrack(int start, string s, vector<string> partition, vector<vector<string>> &res) {
        if (start == s.length()) {
            res.push_back(partition);
            return;
        }
        for (int i=start; i<s.length(); i++) {
            if (isPalindrome(s.substr(start, i-start+1))) {
                partition.push_back(s.substr(start, i-start+1));
                backtrack(i+1, s, partition, res);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        backtrack(0, s, partition, res);
        return res;
    }
};