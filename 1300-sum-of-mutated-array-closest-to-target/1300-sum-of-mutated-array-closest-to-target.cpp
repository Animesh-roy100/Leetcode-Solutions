class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++) {
            prefixSum[i+1] = arr[i]+prefixSum[i];
        }
        
        int ans=0;
        int smallestDiff = INT_MAX;
        
        for(int i=0; i<=arr[n-1]; i++) {
            int index = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
            int currentSum = prefixSum[index] + (n - index) * i;
            
            int diff = abs(currentSum - target);
          
            if (smallestDiff > diff) {
                smallestDiff = diff;
                ans = i;
            }
        }
        
        return ans;
    }
};