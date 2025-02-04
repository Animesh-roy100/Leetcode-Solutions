class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(); 
        if(n==1) return nums[0];

        long long maxSum=nums[0], sum=nums[0];
        int r=1;
        while(r<n) {
            if(nums[r]>nums[r-1]) {
                sum += nums[r];
                maxSum = max(maxSum, sum);
            } else {
                sum=nums[r];
            }
            r++;
        } 

        return maxSum;
    }
};