// Way - 01 : Complete Brute Force
class AllOne {
public:
    unordered_map<string, int> freq;
    AllOne() {
       // nothing to do here
    }
    
    void inc(string key) {
        freq[key]++;
    }
    
    void dec(string key) {
        freq[key]--;
    }
    
    string getMaxKey() {
        int mx = 0;
        string ans = "";
        for(auto& val:freq){
            if(val.second > mx){
                mx = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        int mini = INT_MAX;
        string ans = "";
        for(auto& val:freq){
            if(val.second!=0 and val.second < mini){
                mini = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */