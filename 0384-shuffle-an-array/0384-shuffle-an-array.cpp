class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle = original;
        int n=shuffle.size();
        int leftSize = n;
        for(int i=n-1; i>=0; i--) {
            int j = rand()%leftSize;

            swap(shuffle[i], shuffle[j]);
            leftSize--;
        }

        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */