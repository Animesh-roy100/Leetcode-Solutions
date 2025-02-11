class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxScore=0, score=0;
        int n=tokens.size();
        int l=0, r=n-1;
        while(l<=r) {
            while(l<=r and power >= tokens[l]) {
                power -= tokens[l];
                score++;
                l++;
            }
            maxScore = max(maxScore, score);

            if(l<=r) {
                if(score == 0) break;
                score--;
                power += tokens[r--];
            }
        }

        return maxScore;
    }
};