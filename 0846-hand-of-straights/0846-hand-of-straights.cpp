class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        
        map<int, int> m;
        for(auto i: hand) m[i]++;
        
        for(int i=0; i<n; i++) {
            if(m[hand[i]] == 0) continue;
            for(int j=0; j<groupSize; j++) {
                int currHand = j+hand[i];
                if(m[currHand] == 0) return false;
                m[currHand]--;
            }
        }
        
        return true;
    }
};