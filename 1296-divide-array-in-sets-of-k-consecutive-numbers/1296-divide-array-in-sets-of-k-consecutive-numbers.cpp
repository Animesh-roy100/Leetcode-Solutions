class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k != 0) return false;
        sort(nums.begin(), nums.end());
        
        map<int, int> m;
        for(auto i: nums) m[i]++;
        
        for(int i=0; i<n; i++) {
            if(m[nums[i]] == 0) continue;
            for(int j=0; j<k; j++) {
                int currNum = j+nums[i];
                if(m[currNum] == 0) return false;
                m[currNum]--;
            }
        }
        
        return true;
    }
};