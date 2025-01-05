class Solution {
public:
    bool canTransform(string start, string result) {
        int n=start.length();
        string s1, s2;
        for(int i=0; i<n; i++){
            if(start[i] != 'X') s1 += start[i];
            if(result[i] != 'X') s2 += result[i];
        }

        if(s1 != s2) return false;

        int l=0, r=0;
        while(l<n and r<n) {
            if(start[l] == 'X') l++;
            else if(result[r] == 'X') r++;
            else {
                if((start[l] == 'L' and l<r) or (start[l] == 'R' and l>r)) return false;
                l++, r++;
            }
        }

        return true;
    }
};