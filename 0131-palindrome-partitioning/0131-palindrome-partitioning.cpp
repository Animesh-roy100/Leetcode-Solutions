class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(int i, int j, string &s) {
        while(i<j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> part) {
        if(idx == s.length()) {
            ans.push_back(part);
            return;
        }

        string temp="";
        for(int i=idx; i<s.length(); i++) {
            temp.push_back(s[i]);
            if(isPalindrome(idx, i, s)) {
                part.push_back(temp);
                solve(i+1, s, part);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> part;
        solve(0, s, part);

        return ans;
    }
};