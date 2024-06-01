class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> setNums;
        // for(int i=0; i<nums.size(); i++) {
        //     setNums.insert(nums[i]);
        //     if (i+1 != setNums.size()) {
        //         return true;
        //     }
        // }
        // return false;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};