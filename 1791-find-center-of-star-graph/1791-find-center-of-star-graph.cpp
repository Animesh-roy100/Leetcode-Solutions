class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        
        if(a == edges[1][0] or a == edges[1][1]) return a;
        else return b;
    }
};