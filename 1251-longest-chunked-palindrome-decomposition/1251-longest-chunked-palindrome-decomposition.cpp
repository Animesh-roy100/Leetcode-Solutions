class Solution {
public:
    int longestDecomposition(string s) {
        int n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;

        for(int i=1; i<=n/2; i++) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(n-i, i);

            if(prefix == suffix) {
                return 2 + longestDecomposition(s.substr(i, n - 2*i));
            }
        }

        return 1;
    }
};