class Solution {
private:
    bool canDistribute(vector<int> &candies, long long mid, long long k) {
        long long total=0;
        for(auto &candy: candies) {
            total += candy/mid;
            if(total >= k) return true;
        }

        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long l = 1, r = accumulate(candies.begin(), candies.end(), 0LL);
        int ans=0;

        while(l <= r) {
            long long mid = l + (r - l)/2;

            if(canDistribute(candies, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};