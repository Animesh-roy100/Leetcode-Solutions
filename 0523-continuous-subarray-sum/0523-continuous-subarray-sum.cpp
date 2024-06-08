class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashMap{{0,-1}};
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            
            sum %= k;
            if(hashMap.find(sum) != hashMap.end()) {
                if (i-hashMap[sum] > 1) return true;
            } else {
                hashMap[sum] = i;
            }
        }
        
        return false;
    }
};