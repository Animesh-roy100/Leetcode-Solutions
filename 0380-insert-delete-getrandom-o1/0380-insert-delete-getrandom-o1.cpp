class RandomizedSet {
unordered_map<int, int> m; // val->index
vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;

        v.push_back(val);
        m[val] = v.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;

        int idx = m[val];
        int lastIdx = v.size()-1;

        swap(v[idx], v[lastIdx]);

        m[v[idx]] = idx;
        
        v.pop_back();
        m.erase(val);

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