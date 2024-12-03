class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[0] > target) return 0;
        if(nums[n-1] < target) return n;
        int start=0, end=n-1;
        int res=-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) {
                res = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return res;
    }
};