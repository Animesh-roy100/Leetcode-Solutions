class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int satisfied=0, ans=0;
        
        for(int i=0; i<customers.size(); i++) {
            if(grumpy[i]==0) satisfied+=customers[i];
        } 
        
        int l=0, r=minutes-1;
        for(int i=l; i<=r; i++) {
            if(grumpy[i]==1) {
                satisfied+=customers[i];
            }
        }
        ans = max(ans, satisfied);
        
        while(r<n-1) {
            if(grumpy[l] == 1) satisfied-=customers[l];
            l++;
            r++;
            if(grumpy[r] == 1) satisfied+=customers[r];
            
            ans = max(ans, satisfied);
        }
        
        return ans;
    }
};