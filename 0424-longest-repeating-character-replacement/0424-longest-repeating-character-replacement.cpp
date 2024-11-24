class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0, r=0, maxFreq=0, maxLen=0;
        vector<int> hash(26, 0);
        while(r<n) {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);
            if((r-l+1) - maxFreq > k) {
                hash[s[l]-'A']--;
                // maxFreq=0;
                // for(int i=0; i<27; i++) maxFreq = max(maxFreq, hash[s[l]-'A']);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        
        return maxLen;
    }
};