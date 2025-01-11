class Solution {
public:
    // void solve(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
    //     if(idx==nums.size()) {
    //         ans.push_back(temp);
    //         return;
    //     }

    //     temp.push_back(nums[idx]);
    //     solve(idx+1, nums, temp, ans);
    //     temp.pop_back();
    //     solve(idx+1, nums, temp, ans);
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> temp;
        // solve(0, nums, temp, ans);

        int n=nums.size();
        int totalSubsets = 1<<n; // 2^n total number of subsets

        for(int mask=0; mask<totalSubsets; mask++) {
            vector<int> subset;
            for(int i=0; i<n; i++) {
                if(mask & (1<<i)) { // For each integer, check which bits are set
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};