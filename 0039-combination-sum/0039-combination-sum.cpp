class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &candidate, int target, vector<int> &nums) {
        if(target==0) {
            ans.push_back(nums);
            return;
        }
        if(idx==candidate.size() or target<0) return;
        
        for(int i=idx; i<candidate.size(); i++) {
            nums.push_back(candidate[i]);
            solve(i, candidate, target-candidate[i], nums);
            nums.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<int> nums;
        solve(0, candidate, target, nums);
        return ans;
    }
};