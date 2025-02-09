class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0; // reverse the problem: which are good pairs
        int n=nums.size();

        unordered_map<int, long long> freq;
        long long totalPairs = (long long)n * (n-1) / 2;

        for(int i=0; i<n; i++) {
            int key = nums[i] - i;
            count += freq[key];
            freq[key]++;
        }

        return totalPairs - count;
    }
};