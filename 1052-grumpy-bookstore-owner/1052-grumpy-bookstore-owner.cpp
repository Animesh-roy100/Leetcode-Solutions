class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int ans=0, sum=0;
        
        for(int i=0; i<n; i++) {
            if(grumpy[i]==0) sum += customers[i];
        }
        
        int l=0, r=minutes-1;
        for(int i=l; i<=r; i++) {
            if(grumpy[i]==1) sum += customers[i];

        }
        ans = max(ans, sum);
        
        while(r<n-1) {
            if(grumpy[l] == 1) sum -= customers[l];
            l++;
            r++;
            if(grumpy[r] == 1) sum += customers[r];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};