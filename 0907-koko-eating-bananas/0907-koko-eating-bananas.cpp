class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low = 1, high = 1e9;

        int minCount=high;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(canEat(piles, mid, h)) {
                minCount=mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return minCount;
    }

    bool canEat(vector<int>& piles, long long k, long long h) {
        long long time = 0;
        for (int pile : piles) {
            time += (pile + k - 1) / k; // Ceiling of pile / k
        }
        return time <= h;
    }
};