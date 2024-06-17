class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // sort(hours.begin(), hours.end());
        vector<int> cnt(24, 0);
        long res = 0;
        
        for(int hour: hours) {
            int rem = hour % 24;
            cnt[rem]++;
        }
        
        for(int i=1; i<12; i++) res += cnt[i]*cnt[24-i];
        
        res += 1LL*cnt[0]*(cnt[0]-1)/2;
        res += 1LL*cnt[12]*(cnt[12]-1)/2;
            
        return res;
    }
};