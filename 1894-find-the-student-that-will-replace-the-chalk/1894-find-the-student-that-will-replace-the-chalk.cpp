class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % sum;
        cout<<k<<" ";
        for(int i=0; i<n; i++){
            if(k<chalk[i]) return i;
            k -= chalk[i];
        }
        return -1;
    }
};