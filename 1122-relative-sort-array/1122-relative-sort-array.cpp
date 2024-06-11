class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hashMap;
        for(int i=0; i<arr1.size(); i++) {
            hashMap[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<arr2.size(); i++) {
            if(hashMap.find(arr2[i]) != hashMap.end()) {
                while(hashMap[arr2[i]]-->1) {
                    ans.push_back(arr2[i]);
                }
            }
            ans.push_back(arr2[i]);
        }
        for(auto &it: hashMap) {
            while(it.second--) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};