class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n=s.length();
        int i=0, j=0, ans=0;;
        while(j<n) {
            if(set.find(s[j]) != set.end()) {
                set.erase(s[i]);
                i++;
            } else {
                set.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }
        }
        
        return ans;
    }
};