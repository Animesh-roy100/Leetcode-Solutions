class Solution {
public:
    int solve(vector<vector<int>> &emp, int headID, vector<int> &informTime) {
        int time=0;
        for(int id: emp[headID]) {
            time = max(time, informTime[headID] + solve(emp, id, informTime));
        }    
        
        return time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> emp(n);
        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                emp[manager[i]].push_back(i);
            }
        }
        
        return solve(emp, headID, informTime);
    }
};