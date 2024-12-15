class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0, end=n-1;
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return mid;
            if(nums[mid] > nums[mid+1]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return -1;
    }
};