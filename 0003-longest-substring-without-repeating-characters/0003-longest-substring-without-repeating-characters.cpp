class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.length();
        unordered_map<char, int> um;
        int maxi=0;
        for(char c: s) {
            um[c]++;
            while(um[c] > 1) {
                um[s[l]]--;
                if(um[s[l]] == 0) {
                    um.erase(s[l]);
                }
                l++;

            } 
            r++;
            maxi = max(maxi, r-l);
        }

        return maxi;
    }
};