class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0]==10 or bills[0]==20) return false;
        unordered_map<int, int> umap;
        umap[5]++;
        for(int i=1; i<bills.size(); i++) {
            if(bills[i]==5) {
                umap[5]++;
            }
            else if (bills[i]==10) {
                umap[10]++;
                umap[5]--;
                if(umap[5]<0) return false;
            }
            else {
                umap[20]++;
                if (umap[10]>0) {
                    umap[10]--;
                    umap[5]--;
                }
                else {
                    umap[5]--;
                    umap[5]--;
                    umap[5]--;
                }
                if(umap[5]<0 or umap[10]<0) return false;
            }
        }
        return true;
    }
};