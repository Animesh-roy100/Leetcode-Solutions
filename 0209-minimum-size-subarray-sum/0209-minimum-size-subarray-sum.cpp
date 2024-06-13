class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX, n=nums.size();
        int l=0, r=0, sum=0;
        for(r=0; r<n; r++) {
            sum+=nums[r];  
            while(sum>=target) {
                ans = min(ans, r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};