class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), ans = 0;
        int prefixSum = 0;
        unordered_map<int,int> um;
        um[0] = 1;
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];
            if(um.find(prefixSum-k)!=um.end()) {
                ans += um[prefixSum-k];
            }
            um[prefixSum]++;
        }
        return ans;
    }
};