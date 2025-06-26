class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++) {
            if(um.find(nums[i]) != um.end()) {
                return nums[i];
            }
            um[nums[i]]++;
        }

        return 0;
    }
};