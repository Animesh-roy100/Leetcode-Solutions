class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        for(int i=0; i<s1.length(); i++) {
            count[s1[i]-'a']++;
        }
        int l=0, r=0, n=s1.length();
        for(r=0; r<s2.length(); r++) {
            if(--count[s2[r]-'a'] >= 0) {
                n--;
            }
            while(n==0) {
                if(r-l+1 == s1.length()) return true;
                if(++count[s2[l++]-'a'] > 0) {
                    n++;
                }
            }
        }
        return false;
    }
};