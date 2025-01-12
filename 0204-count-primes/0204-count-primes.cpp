class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;

        vector<bool> numbers(n, false);
        for(int i=2; i*i<n; i++) {
            if(!numbers[i]) {
                int idx = 2;
                int num = i*idx;
                while(num<n) {
                    numbers[num] = true;
                    idx++;
                    num = i*idx;
                }
            }
        }
        int count=0;
        for(int i=2; i<n; i++) {
            if(!numbers[i]) count++;
        }
        return count;
    }
};