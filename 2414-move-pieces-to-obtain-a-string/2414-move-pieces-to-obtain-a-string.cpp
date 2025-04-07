class Solution {
public:
    bool canChange(string start, string target) {
        int i=0, j=0, n=start.size();

        while(i<n or j<n) {
            while(i<n and start[i] == '_') i++;
            while(j<n and target[j] == '_') j++;

            if(i==n or j==n) break;

            if(start[i] != target[j]) return false;
            else if(start[i] == 'L') {
                if(i<j) return false;
            } else if(start[i] == 'R') {
                if(i>j) return false;
            }

            i++;
            j++;
        }

        return i==n and j==n;
    }
};