class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return 1;

        int l=0, r=0, ans=1;
        int mask=0;
        while(r<n) {
            while((mask & nums[r]) != 0) {
                mask ^= nums[l];
                l++;
            }
            mask |= nums[r];
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};