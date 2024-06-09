class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0, n=nums.size();
        // for(int i=0; i<n; i++) {
        //     int sum = nums[i]; 
        //     if(sum%k==0) count++;
        //     for(int j=i+1; j<n; j++) {
        //         sum+=nums[j];
        //         if(sum%k==0) count++;
        //     }
        // }
        unordered_map<int, int> hashMap;
        hashMap[0]=1;
        int sum=0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int reminder = (sum%k+k)%k;
            hashMap[reminder]++;
            if(hashMap[reminder]>1) {
                count += hashMap[reminder]-1;
            }
        }
        return count;
    }
};