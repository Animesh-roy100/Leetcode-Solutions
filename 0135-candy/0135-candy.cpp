class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        for (int i=1; i<n; i++) {
            if(ratings[i]>ratings[i-1]) {
                while(left[i] <= left[i-1]){
                    left[i]++;   
                }
            }
        }
        
        vector<int> right(n, 1);
        for (int i=n-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {
                while(right[i] <= right[i+1]) {
                    right[i]++;   
                }
            }
        }
        
        int sum=0;
        for(int i=0; i<n; i++) {
            int maxRes = max(left[i], right[i]);
            sum += maxRes;
        }
        return sum;
    }
};