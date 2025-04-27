class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=2, count=0;
        while(j<n) {
            if(nums[i+1] == 2*(nums[i] + nums[j])) {
                count++;
            }
            i++;
            j++;
        }

        return count;
    }
};