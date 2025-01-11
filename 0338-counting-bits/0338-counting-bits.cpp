class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++) {
            int count=0;
            int num=i;
            while(num>0) {
                count += (num&1);
                num = num>>1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};