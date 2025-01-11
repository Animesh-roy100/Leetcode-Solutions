class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long lln = n;
        if(n<0) lln *= -1;
        while(lln) {
            if(lln%2==1) {
                ans *= x;
                lln--;
            } else {
                x = x*x;
                lln /= 2;
            }
        }

        if(n<0) ans = (1.0)/ans;

        return ans;
    }
};