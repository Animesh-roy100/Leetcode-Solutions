class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1, 0);

        for(auto query: queries){
            diff[query[0]] += 1;
            diff[query[1]+1] -= 1;
        }

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += diff[i];
            if(sum < nums[i]) return false;
        }

        return true;
    }
};