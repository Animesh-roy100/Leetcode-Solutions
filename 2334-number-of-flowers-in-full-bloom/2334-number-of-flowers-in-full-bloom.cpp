class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for(auto it: flowers) {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for(int i=0; i<people.size(); i++) {
            int flowersBloomBefore = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int flowersDeadBefore = lower_bound(end.begin(), end.end(), people[i]) - end.begin();

            ans.push_back(flowersBloomBefore-flowersDeadBefore);
        }

        return ans;
    }
};