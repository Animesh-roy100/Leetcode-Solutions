class Solution {
public:
    string decodeString(string s) {
        stack<string> strStk;
        stack<int> countStk;
        string currStr="";
        int count=0;

        for(char c: s) {
            if((c-'0') >= 0 and (c-'0') <= 9) {
                count = count*10 + (c-'0');
                // cout<<"count: "<<count<<endl;
            } else if(c == '[') {
                strStk.push(currStr);
                countStk.push(count);
                currStr = "";
                count = 0;
            } else if(c == ']') {
                string str = currStr;
                currStr = strStk.top();
                strStk.pop();

                int cnt = countStk.top();
                countStk.pop();

                while(cnt-->0) {
                    currStr += str;
                }
            } else {
                currStr.push_back(c);
            }
        }

        return currStr;
    }
};