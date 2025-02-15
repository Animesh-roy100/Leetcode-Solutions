class Solution {
public:
    bool canPartition(string s, int num, int idx) {
        if(idx == s.length() and num == 0) return true;
        if(num < 0) return false;

        int leftNum = 0;
        for (int i = idx; i < s.length(); i++) {
            leftNum = (leftNum * 10) + (s[i] - '0'); 

            if(canPartition(s, num - leftNum, i+1)) return true;   
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sqr = i * i;

            if (canPartition(to_string(sqr), i, 0)) {
                ans += sqr;
            }
        }

        return ans;
    }
};