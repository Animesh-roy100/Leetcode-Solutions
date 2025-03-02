class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l=0, r=people.size()-1, count=0;
        
        while(l<=r) {
            int weight = people[l] + people[r];

            if(weight <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }

        return count;
    }
};