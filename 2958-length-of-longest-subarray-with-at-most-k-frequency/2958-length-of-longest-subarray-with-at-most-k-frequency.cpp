class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0, n=nums.size();
        unordered_map<int, int> umap;
        int ans=0;
        for(int r=0; r<n; r++) {
            umap[nums[r]]++;
            while(umap[nums[r]]>k) {
                umap[nums[l++]]--;
                if(umap[nums[r]]==k) break;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};