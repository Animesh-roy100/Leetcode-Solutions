/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int solve(unordered_map<int, Employee*> &um, int &id) {
        if(um.find(id) == um.end()) return 0;
        
        Employee* employee = um[id];
        int totalImp = employee->importance;
        // cout<<totalImp<<endl;
        for(int index: employee->subordinates) {
            totalImp += solve(um, index);
        }
        
        return totalImp;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um;
        
        for(auto employee: employees) {
            um[employee->id] = employee;
        }
        
        return solve(um, id);
    }
};