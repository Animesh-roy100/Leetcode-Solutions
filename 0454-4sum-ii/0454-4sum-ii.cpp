class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum;
        for(int n1: nums1) {
            for(int n2: nums2) {
                sum[n1+n2]++;
            }
        }

        int count=0;
        for(int n3: nums3) {
            for(int n4: nums4) {
                int target = -(n3+n4);
                if(sum.find(target) != sum.end()) {
                    count+=sum[target];
                }
            }
        }

        return count;
    }
};