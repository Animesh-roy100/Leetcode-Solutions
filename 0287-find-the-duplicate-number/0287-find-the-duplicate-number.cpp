class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1, count=0;
        while(low<high) {
            int mid = (low+high)/2;
            count=0;
            for(int i=0; i<n; i++) {
                if(nums[i] <= mid) count++;
            }
            
            if(count > mid) high = mid;
            else low = mid+1;
        }
        
        return low;
    }
};