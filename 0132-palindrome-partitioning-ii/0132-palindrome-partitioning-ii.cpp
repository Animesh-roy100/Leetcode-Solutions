class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        // Step 1: Precompute the palindrome substrings
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) {
            isPalindrome[i][i] = true; // Single character is always a palindrome
        }
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len == 2) {
                        isPalindrome[i][j] = true; // Two same characters are a palindrome
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1]; // Check inner substring
                    }
                }
            }
        }
        
        // Step 2: DP to find the minimum cuts
        vector<int> dp(n, INT_MAX);
        
        for(int i = 0; i < n; i++) {
            if(isPalindrome[0][i]) {
                dp[i] = 0; // If the whole substring from 0 to i is a palindrome, no cut needed
            } else {
                for(int j = 0; j < i; j++) {
                    if(isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1); // If s[j+1...i] is a palindrome, make a cut
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
