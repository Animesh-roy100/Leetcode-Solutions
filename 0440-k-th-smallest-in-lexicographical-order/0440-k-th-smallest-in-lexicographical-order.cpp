class Solution {
public:
   long long count(long long prefix, long long n) {
    long long current = prefix, next = prefix + 1;
    long long steps = 0;

    while (current <= n) {
        steps += min(n + 1, next) - current;
        current *= 10;
        next *= 10;
    }

    return steps;
}

int findKthNumber(int n, int k) {
    long long prefix = 1;
    k--;  

    while (k > 0) {
        long long steps = count(prefix, n);

        if (steps <= k) {

            k -= steps;
            prefix++;
        } else {

            prefix *= 10;
            k--;
        }
    }

    return prefix;
}
};