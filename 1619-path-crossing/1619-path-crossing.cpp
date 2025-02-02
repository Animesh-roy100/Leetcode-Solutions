class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        set<pair<int, int>> st;
        st.insert({x, y});
        for(char c: path) {
            if(c == 'N') y++;
            if(c == 'E') x++;
            if(c == 'S') y--;
            if(c == 'W') x--;
            
            if(st.find({x, y}) != st.end()) return true;
            st.insert({x, y});
        }

        return false;
    }
};