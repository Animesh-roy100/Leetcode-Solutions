class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0, end=nums.size()-1;
        
        // base condition
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            
            if(mid%2 == 0) {
                if(nums[mid] == nums[mid-1]) {
                    end = mid-1;
                } else if(nums[mid] == nums[mid+1]) {
                    start = mid+1;
                }
            } else if(mid%2 == 1) {
                if(nums[mid] == nums[mid-1]) {
                    start = mid+1;
                } else if(nums[mid] == nums[mid+1]) {
                    end = mid-1;
                }
            }
        }
        
        return -1;
    }
};