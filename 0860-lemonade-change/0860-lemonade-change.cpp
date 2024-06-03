class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0]==10 or bills[0]==20) return false;
        unordered_map<int, int> umap;
        int five=0, ten=0;
        five++;
        for(int i=1; i<bills.size(); i++) {
            if(bills[i]==5) {
                five++;
            }
            else if (bills[i]==10) {
                ten++;
                five--;
                if(five<0) return false;
            }
            else {
                if (ten>0) {
                    ten--;
                    five--;
                }
                else {
                    five-=3;
                }
                if(five<0 or ten<0) return false;
            }
        }
        return true;
    }
};