class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        // int l=0, r=k-1, ans=0;
        // while(r<n) {
        //     if(nums[l]==0) {
        //         ans++;
        //         for(int i=l; i<l+k; i++) {
        //             if(nums[i]==1) nums[i]=0;
        //             else nums[i]=1;
        //         }
        //     }
        //     l++; 
        //     r++;
        // }
        
        vector<int> flips(n, 0);
        int ans=0, flip=0;
        for(int i=0; i<n; i++) {
            if(i>=k and flips[i-k]==1) flip ^= 1;
            
            if(nums[i]==flip) {
                if(i+k > n)  return -1;
                flips[i]=1;
                flip ^= 1;
                ans++;
            }
        }
        
        // for(int i=0; i<n; i++) {
        //     if(nums[i]==0) return -1;
        // }
        
        return ans;
    }
};