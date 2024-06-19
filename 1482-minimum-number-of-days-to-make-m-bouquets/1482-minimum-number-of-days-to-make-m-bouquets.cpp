class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*n < 1LL*m*k) return -1;
        
        int high=INT_MIN, low=INT_MAX;
        for(int i=0; i<n; i++) {
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }
        // cout<<low<<" "<<high<<" "<<endl;
        int ans = high;
        while(low<=high) {
            int mid = low + (high-low)/2;
            // cout<<mid<<" ";
            int count=0, bloomCount=0;
            for(int i=0; i<n; i++) {
                if(mid >= bloomDay[i]) {
                    count++;
                } else {
                    bloomCount += (count/k);
                    count = 0;
                }
                // cout<<bloomCount<<" ";
            }
            bloomCount += (count/k);
            // cout<<bloomCount<<" "<<endl;
            if(bloomCount >= m) {
                // cout<<mid<<" ";
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};