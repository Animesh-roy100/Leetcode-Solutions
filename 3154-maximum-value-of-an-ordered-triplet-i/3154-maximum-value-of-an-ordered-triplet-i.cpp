class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxEle = 0, maxDiff = 0;
        for(long num: nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxEle - num);
            maxEle = max(maxEle, num);
        }

        return maxTriplet;
    }
};