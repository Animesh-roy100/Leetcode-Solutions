class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist=0;
        for(int i=0; i<nums.size(); i++) {
            if(dist < 0) return false;
            if(dist < nums[i]) dist = nums[i];
            dist--;
        }
        
        return true;
    }
};