class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size(), i=0, j=0, currCnt=0;
        unordered_map<int, int> um;
        while(j<n) {
            currCnt += um[nums[j]];
            um[nums[j]]++;

            while(i<j and currCnt >= k) {
                ans += n-j;
                um[nums[i]]--;
                currCnt -= um[nums[i]];
                i++;
            }
            j++;
        }

        return ans;
    }
};