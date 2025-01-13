class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        for(int num: nums) {
            for(int i=0; i<=31; i++) {
                bits[i] += (num>>i) & 1;
            }
        }

        int ans=0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] % 3 != 0) {
                if (i == 31) {
                    ans -= (1LL << i);
                } else {
                    ans += (1 << i);
                }
            }
        }

        return ans;
    }
};