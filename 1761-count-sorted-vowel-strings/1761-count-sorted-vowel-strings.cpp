class Solution {
public:
    int solve(int i, int vowelIdx, int n) {
        if(vowelIdx == 5) return 0;
        if(i == n) return 1;

        int take = solve(i+1, vowelIdx, n);
        int notTake = solve(i, vowelIdx+1, n);

        return take + notTake;
    }

    int countVowelStrings(int n) {
        return solve(0, 0, n);
    }
};