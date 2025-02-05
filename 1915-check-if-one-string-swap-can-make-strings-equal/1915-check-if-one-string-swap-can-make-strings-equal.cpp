class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.size();
        vector<int> mismatch_indices;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                mismatch_indices.push_back(i);
            }
            if (mismatch_indices.size() > 2) {
                return false; 
            }
        }

        if (mismatch_indices.size() == 2) {
            int i = mismatch_indices[0];
            int j = mismatch_indices[1];
            if (s1[i] == s2[j] && s1[j] == s2[i]) {
                return true;
            }
        }

        return false;
    }
};