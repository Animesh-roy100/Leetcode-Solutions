class Solution {
public:
    void solve(string s, int n, unordered_set<string> &set, string &ans) {
        if(s.length() == n) {
            if(set.find(s) == set.end()) {
                ans = s;
            }
            return;
        }

        for(auto c: {'0', '1'}) {
            s.push_back(c);
            solve(s, n, set, ans);
            s.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> set(nums.begin(), nums.end());
        string ans="";
        solve("", nums.size(), set, ans);
        return ans;
    }
};