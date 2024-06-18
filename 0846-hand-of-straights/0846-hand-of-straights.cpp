class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> umap;
        for(int i=0; i<hand.size(); i++) {
            umap[hand[i]]++;
        }
        
        for(auto &it:umap) {
            int value = it.second;
            if(value>0) {
                for(int i=it.first; i<it.first+groupSize; i++) {
                    umap[i] -= value;
                    if (umap[i] < 0) return false;
                }
            }
        }
        return true;
    }
};