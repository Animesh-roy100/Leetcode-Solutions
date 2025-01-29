class Solution {
public:
    int solve(int idx, string s, unordered_set<string> &uniqueSubstr) {
        if(idx == s.length()) return uniqueSubstr.size();

        string temp="";
        int maxNum=0;
        for(int i=idx; i<s.length(); i++){
            temp += s[i];
            if(uniqueSubstr.find(temp) == uniqueSubstr.end()) {
                uniqueSubstr.insert(temp);
                maxNum = max(maxNum, solve(i+1, s, uniqueSubstr));
                uniqueSubstr.erase(temp);
            }
        }

        return maxNum;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstr;
        return solve(0, s, uniqueSubstr);
    }
};