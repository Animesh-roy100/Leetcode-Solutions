class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0, end=n-1;
        while(start<=end) {
            int mid = (end+start)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[start]) {
                if(target >= nums[start] and target < nums[mid]) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            } else {
                if(target > nums[mid] and target <= nums[end]) {
                    start = mid+1; 
                } else {
                    end = mid-1;
                }
            }
        }
        
        return -1;
    }
};