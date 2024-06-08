class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
//         vector<int> left(n, 1);
//         for (int i=1; i<n; i++) {
//             if(ratings[i]>ratings[i-1]) {
//                 left[i] = left[i-1]+1;   
//             }
//         }
    
//         int curr=1, sum=left[n-1];
//         for (int i=n-2; i>=0; i--) {
//             if(ratings[i]>ratings[i+1]) {
//                 curr++;
//             } else {
//                 curr=1;
//             }
//             sum += max(left[i], curr);
//         }
        
//         return sum;
        
        int sum=1, i=1;
        while(i<n) {
            if(ratings[i] == ratings[i-1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n and ratings[i]>ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down=1;
            while(i<n and ratings[i]<ratings[i-1]) {
                sum += down;
                i++;
                down++;
            }
            if (down>peak) sum += (down-peak);
        }
        return sum;
    }
};