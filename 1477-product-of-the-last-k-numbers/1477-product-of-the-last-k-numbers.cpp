class ProductOfNumbers {
public:
    vector<long long> prefix = {1};
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0) {
            prefix = {1};
        } else {
            long long lastProd = prefix.back();
            prefix.push_back(lastProd * num);
        }
    }
    
    int getProduct(int k) {
        int n=prefix.size();
        if(k >= n) return 0;
        return prefix[n-1] / prefix[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */