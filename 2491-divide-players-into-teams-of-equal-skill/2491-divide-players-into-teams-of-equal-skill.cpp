class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) return skill[0]*skill[1];
        
        sort(skill.begin(), skill.end());
        long long chem = skill[0]*skill[n-1];
        int totalSkill = skill[0] + skill[n-1];
        
        for(int i=1; i<n/2; i++) {
            if(totalSkill != skill[i] + skill[n-i-1]) {
                return -1;
            }
            chem += skill[i]*skill[n-i-1];
        }
        
        return chem;
    }
};