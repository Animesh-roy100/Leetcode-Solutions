class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0, l=0, r=2;
        while(r<n) {
            if(nums[l]==0) {
                ans++;
                for(int i=l; i<l+3; i++) {
                    if(nums[i]==0) nums[i]=1;
                    else nums[i]=0;
                }
            }
            l++;
            r++;
        }
        
        for(int i=0; i<n; i++){
            if(nums[i]==0) return -1;
        }
        return ans;
    }
};