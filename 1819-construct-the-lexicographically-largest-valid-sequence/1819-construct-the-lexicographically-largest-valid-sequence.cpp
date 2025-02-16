class Solution {
public:
    bool validSequence(int idx, int n, vector<int> &ans, vector<bool> &vis) {
        if(idx == ans.size()) return true;

        if(ans[idx] > 0) return validSequence(idx+1, n, ans, vis);

        for(int i=n; i>=1; i--) {
            int nextIdx = (i==1) ? idx : (idx + i);

            if(vis[i] or nextIdx >= ans.size()) continue;
            if(ans[nextIdx] > 0) continue;


            ans[idx] = i;
            ans[nextIdx] = i;
            vis[i] = true;

            if(validSequence(idx + 1, n, ans, vis)) return true;

            ans[idx] = 0;
            ans[nextIdx] = 0;
            vis[i] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n*2 - 1, 0);
        vector<bool> vis(n+1, false);

        validSequence(0, n, ans, vis);
        return ans;
    }
};