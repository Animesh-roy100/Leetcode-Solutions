class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc=1, maxDec=1;
        int l=0, r=1, n=nums.size();
        while(r<n) {
            if(nums[r-1] < nums[r]) {
                cout<<r-l+1<<endl;
                maxInc = max(maxInc, r-l+1);
            } else l = r;
            r++;
        }

        l=0, r=1;
        while(r<n) {
            if(nums[r-1] > nums[r]) {
                maxDec = max(maxDec, r-l+1);
            } else l = r;
            r++;
        }

        return max(maxInc, maxDec);
    }
};