class Solution {
public:
    bool check(vector<int> &pos, int minDist, int m) {
        int prevPos = pos[0];
        int count=1;
        for(int i=1; i<pos.size(); i++) {
            int currPos = pos[i];
            if(currPos - prevPos >= minDist) {
                count++;
                prevPos = currPos;
            }
        }
        if(count>=m) return true;
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int low=1, high=position[n-1];
        while(low<high) {
            int mid = (high+low+1)/2;
            
            if(check(position, mid, m)) {
                low = mid;
            } else {
                high = mid-1;
            }
        }
        
        return low;
    }
};