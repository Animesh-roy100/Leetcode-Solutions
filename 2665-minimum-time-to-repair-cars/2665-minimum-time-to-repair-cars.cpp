class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int n=ranks.size();
        long long l=ranks[0], r=(long long)ranks[n-1]*cars*cars;
        long long ans=0;

        while(l<=r) {
            long long mid = l + (r-l)/2;

            int totalCars=0;
            for(int rank: ranks) {
                totalCars += floor(sqrt(mid/rank));
                if(totalCars >= cars) break;
            }

            if(totalCars >= cars) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};