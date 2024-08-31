class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int res=0;
        for(int ans: answers) {
            if(ans==0) res++;
            else {
                if(mp[ans]==0) res += ans+1;
                mp[ans]++;
                if(mp[ans]==ans+1) mp[ans]=0;
            }
        }
        return res;
    }
};