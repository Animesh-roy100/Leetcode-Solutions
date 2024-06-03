class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());
        if (power < tokens[0]) return 0;
        int score=0, res = 0;
        int i=0, j=tokens.size()-1;
        while (i<=j) {
            while (i<=j && tokens[i]<=power) {
                score++;
                power -= tokens[i++];
            }
            res = max(res, score);
            
            if(i<=j) {
                if(score==0) break;
                score--;
                power += tokens[j--];
            }
            
        }
        return res;
    }
};