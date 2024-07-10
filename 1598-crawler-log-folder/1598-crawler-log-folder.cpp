class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        
        for(int i=0; i<logs.size(); i++) {
            if(logs[i] == "../") {
                if(!stk.empty()) {
                    // cout<<"hi"<<endl;
                    stk.pop();   
                }
            } else if (logs[i] != "./") {
                stk.push(logs[i]);
            }
        }
        
        // cout<<stk.top();
        
        return stk.size();
    }
};