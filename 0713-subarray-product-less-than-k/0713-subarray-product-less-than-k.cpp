class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        // sort(nums.begin(), nums.end());
        // int count=0, i=0;
        // while(i<nums.size()) {
        //     if(nums[i]<=k) {
        //         count++;
        //         int j=i+1, product=nums[i];
        //         while(j<nums.size()) {
        //             product *= nums[j];
        //             if(product<=k) {
        //                 count++;
        //             } else {
        //                 break;
        //             }
        //             j++;
        //         }
        //     }
        //     i++;
        // }
        
        int count=0, prod=1;
        for (int l=0, r=0; r<nums.size(); r++) {
            prod *= nums[r];
            while(prod >= k) {
                prod /= nums[l++];
            }
            count += r-l+1;
        }
        
        return count;
    }
};