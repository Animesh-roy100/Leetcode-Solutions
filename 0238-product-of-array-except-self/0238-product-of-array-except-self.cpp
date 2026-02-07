class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // vector<int> suffix(n), prefix(n);
        int left=1, right=1;
        vector<int> result(n, 1);

        for(int i=0; i<n; i++) {
            result[i] *= left;
            left *= nums[i];

            result[n-i-1] *= right;
            right *= nums[n-i-1];
        }

        return result;
    }
};