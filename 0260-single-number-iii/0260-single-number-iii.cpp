class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;

        // XOR all the numbers
        int xorNum=0;
        for(int num : nums) xorNum ^= num;

        // check for setbit index
        int mask=1;
        while(!(xorNum & mask)) {
            mask = mask << 1;
        }

        int xor1=0, xor2=0;
        for(int num: nums) {
            if(num & mask) xor1 ^= num;
            else xor2 ^= num;
        }

        ans.push_back(xor1);
        ans.push_back(xor2);

        return ans;
    }
};