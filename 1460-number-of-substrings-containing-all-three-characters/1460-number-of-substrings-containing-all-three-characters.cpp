class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        int l=0, r=0, ans=0;
        unordered_map<char, int> um;

        while(r<n) {
            um[s[r]]++;

            while(um.size() == 3 and l<=r) {
                ans += n-r;
                um[s[l]]--;
                if(um[s[l]] == 0) um.erase(s[l]);
                l++;
            }

            r++;
        }

        return ans;
    }
};