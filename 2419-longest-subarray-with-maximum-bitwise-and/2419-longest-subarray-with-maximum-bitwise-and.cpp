class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle=0, count=0, ans=0;
        for(int i=0; i<nums.size(); i++) {
            if(maxEle == nums[i]) {
                count++;
            } else if (maxEle < nums[i]) {
                maxEle = nums[i];
                count=1;
                ans=1;
            } else {
                count=0;
            }
            ans = max(count, ans);
        }
        
        return ans;
    }
};