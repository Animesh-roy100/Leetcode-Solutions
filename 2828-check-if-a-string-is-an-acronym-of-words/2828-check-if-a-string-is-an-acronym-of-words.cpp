class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.length()) return false;
        
        int i=0;
        for(string word: words) {
            if(word[0] == s[i]) i++;
            else return false;
        }
        
        return true;
    }
};