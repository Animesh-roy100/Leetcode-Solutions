class NumberContainers {
public:
    unordered_map<int, int> container; // {index, number}
    unordered_map<int, set<int>> numberIdx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(container.find(index) != container.end()) {
            int oldNum = container[index];
            numberIdx[oldNum].erase(index);

            if(numberIdx[oldNum].empty()) {
                numberIdx.erase(oldNum);
            }
        }

        container[index] = number;
        numberIdx[number].insert(index);
    }
    
    int find(int number) {
        return (numberIdx.find(number) != numberIdx.end()) ? *numberIdx[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */