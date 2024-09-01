class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto s: details) {
            if(stoi(s.substr(11, 2)) > 60) count++;
        }
        return count;
    }
};