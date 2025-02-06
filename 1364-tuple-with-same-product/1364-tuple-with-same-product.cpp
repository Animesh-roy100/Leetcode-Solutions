class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n=nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                freq[nums[i] * nums[j]]++;
            }
        }
        int count=0;
        for(auto it: freq) {
            if(it.second>1) {
                int num = it.second;
                count += 8 * ((num * (num-1))/2);
            }
        }

        return count;
    }
};