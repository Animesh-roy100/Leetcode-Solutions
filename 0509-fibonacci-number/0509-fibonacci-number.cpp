class Solution {
public:
    int helper(int n) {
        if (n<=1) return n;
        return helper(n-1) + helper(n-2);
    }
    int fib(int n) {
        return helper(n);
    }
};