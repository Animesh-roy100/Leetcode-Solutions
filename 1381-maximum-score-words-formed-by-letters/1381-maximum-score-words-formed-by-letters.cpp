class Solution {
public:
    int maxScore=0;

    void backtrack(int idx, vector<string> &words, unordered_map<char, int> &letterCount, vector<int> &score, int currScore) {
        if(idx == words.size()) {
            maxScore = max(maxScore, currScore);
            return;
        }

        // skip the curr word
        backtrack(idx+1, words, letterCount, score, currScore);

        unordered_map<char, int> clone = letterCount;
        int wordScore=0;
        bool canForm=true;

        for(auto c: words[idx]) {
            if(clone.find(c) == clone.end() or clone[c] == 0) {
                canForm=false;
                break;
            }
            
            clone[c]--;
            wordScore += score[c-'a'];
        }

        if(canForm) {
            backtrack(idx+1, words, clone, score, currScore + wordScore);
        }

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;
        for(auto &c: letters) letterCount[c]++;

        backtrack(0, words, letterCount, score, 0);

        return maxScore;
    }
};