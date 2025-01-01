class Solution {
public:
    void solve(int idx, string curr, long prev, long res, string num, int target, vector<string> &ans) {
        if(idx == num.length()) {
            if(res == target) {
                ans.push_back(curr);
                return;
            }
        }

        long currRes=0;
        string str="";

        for(int i=idx; i<num.length(); i++) {
            if (i>idx && num[idx] == '0') break;

            str += num[i];
            currRes = currRes*10 + (num[i]-'0');

            if(idx == 0) {
                solve(i+1, str, currRes, currRes, num, target, ans);
            } else {
                solve(i+1, curr+"+"+str, currRes, res+currRes, num, target, ans);
                solve(i+1, curr+"-"+str, -currRes, res-currRes, num, target, ans);
                solve(i+1, curr+"*"+str, prev*currRes, res-prev+(prev*currRes), num, target, ans);
            }
        }

    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, "", 0, 0, num, target, ans);
        return ans;
    }
};