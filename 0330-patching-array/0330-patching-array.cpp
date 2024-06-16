class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        long missing=1;
        int i=0;
        
        while(missing<=n) {
            if(i<nums.size() and nums[i] <= missing) {
                missing += nums[i];
                i++;
            } else {
                missing *= 2;
                ans++;
            }
        }
        return ans;
    }
};