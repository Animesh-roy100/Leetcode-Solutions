class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixSum;
        long long sum=0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            prefixSum.push_back(sum/(i+1));
        }
        
        long long minDiff=prefixSum.back();
        int index=n-1;
        sum=0;
        for(int i=n-1; i>0; i--) {
            sum += nums[i];
            long long avg = sum/(n-i);
            // cout<<avg<<" ";
            long long diff = abs(prefixSum[i-1] - avg);
            cout<<diff<<" ";
            if(minDiff >= diff) {
                minDiff = diff;
                index = i-1;
                // cout<<index<<" ";
            }
        }
        return index;
    }
};