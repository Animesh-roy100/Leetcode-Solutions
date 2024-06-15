class Solution {
public:
    bool isUgly(int n) {
        if (n==0) return false;
        vector<int> prime({2, 3, 5});
        for(int i=0; i<prime.size(); i++) {
            while(n%prime[i]==0) {
                n/=prime[i];
            }
        }
        if(n==1) return true;
        return false;
    }
};