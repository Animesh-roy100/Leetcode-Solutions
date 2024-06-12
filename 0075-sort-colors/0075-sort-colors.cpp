class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int zero=0, one=0, two=0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i]==0) zero++;
        //     else if(nums[i]==1) one++;
        //     else two++;
        // }
        // int i=0;
        // while(i<nums.size()) {
        //     if(zero>0) {
        //         while(zero--) {
        //             nums[i]=0;
        //             i++;
        //         }
        //     }
        //     if(one>0) {
        //         while(one--) {
        //             nums[i]=1;
        //             i++;
        //         }
        //     }
        //     if(two>0) {
        //          while(two--) {
        //             nums[i]=2;
        //             i++;
        //         }
        //     }
        // }
        int n = nums.size();
        int l=0, r=n-1, mid=0;
        while(mid<=r) {
            if(nums[mid]==0) swap(nums[mid], nums[l++]);
            else if (nums[mid]==2) swap(nums[mid--], nums[r--]);
            mid++;
        }
    }
};