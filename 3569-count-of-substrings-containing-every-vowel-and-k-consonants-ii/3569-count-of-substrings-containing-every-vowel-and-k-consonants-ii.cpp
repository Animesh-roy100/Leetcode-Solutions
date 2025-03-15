class Solution {
public:
    long long atleast(string word, int k) {
        int n = word.size();
        long long ans = 0;
        unordered_map<char, int> vowelsCount;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int l = 0, r = 0, consonent = 0;

        while (r < n) {
            char currChar = word[r];

            if (vowels.find(currChar) != vowels.end()) {
                vowelsCount[currChar]++;
            } else {
                consonent++;
            }

            while (vowelsCount.size() == 5 && consonent >= k && l <= r) {
                ans += n-r;

                char leftChar = word[l];
                if (vowels.find(leftChar) != vowels.end()) {
                    vowelsCount[leftChar]--;
                    if (vowelsCount[leftChar] == 0) {
                        vowelsCount.erase(leftChar);
                    }
                } else {
                    consonent--;
                }
                l++;
            }

            r++;
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atleast(word, k) - atleast(word, k+1);
    }
};