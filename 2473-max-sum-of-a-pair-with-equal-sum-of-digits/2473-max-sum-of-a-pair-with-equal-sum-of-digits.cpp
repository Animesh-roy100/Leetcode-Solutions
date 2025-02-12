class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size(), ans=-1;
        unordered_map<int, int> um;

        for(int num: nums) {
            int digitSum=0;
            string numStr = to_string(num);
            for(char c: numStr) digitSum += (c-'0');

            if(um.find(digitSum) != um.end()) {
                ans = max(ans, num + um[digitSum]);
            }
            um[digitSum] = max(um[digitSum], num);
        }

        return ans;
    }
};