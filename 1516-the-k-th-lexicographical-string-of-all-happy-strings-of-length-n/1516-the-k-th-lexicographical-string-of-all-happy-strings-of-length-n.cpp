class Solution {
public:
    void solve(int &count, int n, int k, string &s, char prev, string &res) {
        if(s.length() == n) {
            count++;
            if(count == k) {
                res = s;
            }
            return;
        }

        for(char c: {'a', 'b', 'c'}) {
            if(c != prev) {
                s.push_back(c);
                solve(count, n, k, s, c, res);
                s.pop_back();
                if(count>=k) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        string s="", res="";
        int count=0;
        solve(count, n, k, s, 'd', res);
        return res;
    }
};