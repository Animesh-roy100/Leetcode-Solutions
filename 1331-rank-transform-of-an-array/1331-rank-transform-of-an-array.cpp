class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> um;
        for(int num: sortedArr) {
            if(um.find(num) == um.end()) {
                int size = um.size();
                um[num] = size+1;
            }
        }
        
        for(int i=0; i<arr.size(); i++) {
            int rank = um[arr[i]];
            arr[i] = rank;
        }
        
        return arr;
    }
};