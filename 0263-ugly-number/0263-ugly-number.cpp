class Solution {
public:
    bool isUgly(int n) {
        if (n==0) return false;
        // vector<int> prime({2, 3, 5});
        // for(int i=0; i<prime.size(); i++) {
        //     while(n%prime[i]==0) {
        //         n/=prime[i];
        //     }
        // }
        while(n%2==0) {
            n/=2;
        }
        while(n%3==0) {
            n/=3;
        }
        while(n%5==0) {
            n/=5;
        }
        if(n==1) return true;
        return false;
    }
};