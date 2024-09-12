class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        vector<bool> v(26, false);
        for(auto c: allowed) v[c-'a']=true;
        
        for(int i=0; i<words.size(); i++) {
            for(auto c: words[i]) {
                if(!v[c-'a']){
                    res--;
                    break;
                }
            }
        }
        
        return res;
    }
};