class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &candi, int target, vector<int> &nums){
        if(target==0) {
            ans.push_back(nums);
            return;
        }
        
        if(idx==candi.size() or target<0) return;
        
        for(int i=idx; i<candi.size(); i++) {
            // skip duplicate
            if (i > idx && candi[i] == candi[i - 1]) continue;
            nums.push_back(candi[i]);
            solve(i+1, candi, target-candi[i], nums);
            nums.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<int> nums;
        solve(0, candi, target, nums);
        return ans;
    }
};