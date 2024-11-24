class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int sum=0, ans=0;
        unordered_map<int, int> um;
        um[sum] = 1;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int target = sum - goal;
            if(um.find(target) != um.end()) {
                ans += um[target];
            }
            um[sum]++;
        }
        
        return ans;
    }
};