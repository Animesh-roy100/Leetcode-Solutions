class Solution {
public:
    int count(string ans, int k, char ch) {
        int l=0, r=0, diffChar=0, maxCount=0;
        while(r<ans.length()) {
            if(ans[r] != ch) {
                diffChar++;
                while(diffChar>k) {
                    if(ans[l++] != ch) diffChar--;
                }
            }
            maxCount = max(maxCount, r-l+1);
            r++;
        }    
        return maxCount;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(count(answerKey, k, 'T'), count(answerKey, k, 'F'));
    }
};