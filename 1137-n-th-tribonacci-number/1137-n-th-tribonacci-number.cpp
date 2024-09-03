class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        vector<int> tribo(n+1);
        tribo[0] = 0;
        tribo[1] = 1;
        tribo[2] = 1;
        for(int i=3; i<n+1; i++) {
            tribo[i] = tribo[i-1] + tribo[i-2] + tribo[i-3];
        }
        return tribo[n];
    }
};