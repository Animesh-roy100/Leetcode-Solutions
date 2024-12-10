class Solution {
public:
    int solve(int start, int end, string &s, int k) {
        if(end-start+1 < k) return 0;
        
        vector<int> freq(26, 0);
        for(int i=start; i<=end; i++) freq[s[i]-'a']++;
        
        int maxLen=0;
        for(int i=start; i<=end; i++) {
            if(freq[s[i]-'a'] < k) {
                return max(solve(start, i-1, s, k), solve(i+1, end, s, k));
            }
        }
        
        return end-start+1;
    }
    
    int longestSubstring(string s, int k) {
        int n=s.length();
        return solve(0, n-1, s, k);
        
//         int n=s.length();
//         vector<int> freq(26, 0);
//         for(char c: s) freq[c-'a']++;
        
//         int start=0, maxLen=0;
//         bool allCharsIncluded = true;
//         for(int end=0; end<n; end++) {
//             if(freq[s[end]-'a'] < k) {
//                 string subStr = s.substr(start, end);
//                 maxLen = max(maxLen, longestSubstring(subStr, k));
//                 start=end+1;
//                 allCharsIncluded = false;
//             }
//         }
        
//         if(allCharsIncluded) {
//             return s.length();
//         } else {
//             return max(maxLen, longestSubstring(s.substr(start), k));
//         }
    }
};