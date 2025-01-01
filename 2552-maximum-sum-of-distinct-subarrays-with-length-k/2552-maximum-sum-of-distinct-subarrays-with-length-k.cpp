class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long l=0, r=0, n=nums.size(), sum=0;
        long long maxi=0;
        unordered_map<int, int> um;
        for(int r=0; r<n; r++) {
            sum += nums[r];
            um[nums[r]]++;
            if(r-l+1 == k) {
                if(um.size() == r-l+1) {
                    maxi = max(maxi, sum);
                }
                sum -= nums[l];
                um[nums[l]]--;
                if(um[nums[l]] == 0) um.erase(nums[l]);
                l++;
            }
        }
        return maxi;
    }
};