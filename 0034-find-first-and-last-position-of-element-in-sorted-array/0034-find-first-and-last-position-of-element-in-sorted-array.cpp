class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n=nums.size();
        int start=0, end=n-1;
        int firstOcc=-1, lastOcc=-1;
        
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) {
                firstOcc = mid;
                end = mid-1;
            } else if(nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        start=0, end=n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) {
                lastOcc = mid;
                start = mid+1;
            } else if(nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        ans[0] = firstOcc;
        ans[1] = lastOcc;
        return ans;
    }
};