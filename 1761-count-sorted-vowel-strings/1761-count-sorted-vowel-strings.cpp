class Solution {
public:
    int solve(int i, int vowelIdx, int n, vector<char> &vowels) {
        if(vowelIdx == vowels.size()) return 0;
        if(i == n) return 1;

        int take = solve(i+1, vowelIdx, n, vowels);
        int notTake = solve(i, vowelIdx+1, n, vowels);

        return take + notTake;
    }

    int countVowelStrings(int n) {
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

        return solve(0, 0, n, vowels);
    }
};