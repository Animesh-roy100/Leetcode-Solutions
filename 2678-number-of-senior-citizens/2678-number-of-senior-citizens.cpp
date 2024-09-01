class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto s: details) {
            string str = s.substr(11, 2);
            cout<<str<<" ";
            if(stoi(str) > 60) {
                count++;
            }
        }
        return count;
    }
};