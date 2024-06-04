class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        
        for(char c:s) {
            m[c]++;
        }
        
        int count=0;
        bool flag=false;
        
        for(auto &it: m) {
            if(it.second%2 == 0) count += it.second;
            else flag=true, count += it.second-1;
        }
        if(flag) count++;
        
        return count;
    }
};