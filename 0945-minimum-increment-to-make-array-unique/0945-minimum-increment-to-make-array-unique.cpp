class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // unordered_set<int> hashSet;
        int ans=0;
        // for(int i=0; i<nums.size(); i++) {
        //     while(hashSet.find(nums[i]) != hashSet.end()) {
        //         nums[i]++;
        //         ans++;
        //     }
        //     hashSet.insert(nums[i]);
        // }
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<=nums[i-1]) ans += (nums[i-1]+1 - nums[i]),nums[i] = nums[i-1]+1;
        }
        return ans;
    }
};