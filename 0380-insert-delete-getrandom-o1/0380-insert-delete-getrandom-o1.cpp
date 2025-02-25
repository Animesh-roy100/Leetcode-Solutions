class RandomizedSet {
unordered_set<int> set;
vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) != set.end()) return false;
        set.insert(val);
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(set.find(val) == set.end()) return false;

        set.erase(val);

        int n=v.size();
        for(int i=0; i<n; i++) {
            if(v[i] == val) {
                swap(v[i], v[n-1]);
                v.pop_back();
                break;
            }
        }

        return true;
    }
    
    int getRandom() {
        int n=v.size();
        int randNum = rand()%n;
        return v[randNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */