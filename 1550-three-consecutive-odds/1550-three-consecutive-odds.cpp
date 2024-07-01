class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd=0;
        for(int r=0; r<arr.size(); r++) {
            if(arr[r]%2 == 1) {
                odd++;
            } else {
                odd = 0;
            }
            
            if(odd==3) return true;
        }
        
        return false;
    }
};