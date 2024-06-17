class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 1) return true;
        vector<long> v;
        long i=0;
        while(i*i <= c) {
            if(i*i == c) return true;
            v.push_back(i);
            i++;
        }
        
        int l=0, r=v.size()-1;
        while(l<=r) {
            if(v[l]*v[l] + v[r]*v[r] > c){
                r--;
            } else if (v[l]*v[l] + v[r]*v[r] < c) {
                l++;
            } else {
                return true;
            }
        }
        
        
        return false;
    }
};