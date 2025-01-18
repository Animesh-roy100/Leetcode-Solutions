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
        vector<int> prefixSum(n, 0);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = prefixSum[n-1];
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