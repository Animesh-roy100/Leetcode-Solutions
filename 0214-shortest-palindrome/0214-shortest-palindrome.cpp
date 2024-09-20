class Solution {
public:
    void generateLPS(string& s, vector<int>& LPS) {
        int left = 0, right = 1, n = s.length();
        while (right < n) {
            if (s[right] == s[left]) {
                LPS[right] = left + 1;
                left++;
                right++;
            } else if (left == 0) {
                LPS[right] = 0;
                right++;
            } else
                left = LPS[left - 1];
        }
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        s.push_back('#');
        s.insert(s.end(), s.rbegin() + 1, s.rend());
        vector<int> LPS(2 * n + 1, 0);
        generateLPS(s, LPS);
        return s.substr(n + 1, n - LPS.back()) + s.substr(0, n);
    }
};