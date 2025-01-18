class Solution {
public:
    int solve(vector<int> &nums, int sum) {
        int splits=1, splitSum=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] + splitSum <= sum) {
                splitSum += nums[i];
            } else {
                splits++;
                splitSum = nums[i];
            }
        }

        return splits;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int num: nums) high += num;
        int ans=-1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            
            if(solve(nums, mid) <= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};