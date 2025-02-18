class Solution {
private:
    vector<int> sum;
    int totalSum;
public:

    Solution(vector<int>& w) {
        // sum vector stores the cumulative sum
        sum.push_back(w[0]);
        for(int i=1; i<w.size(); i++) {
            sum.push_back(w[i] + sum.back());
        }
        totalSum = sum.back();
    }
    
    int pickIndex() {
        int random = rand() % totalSum;
        return upper_bound(sum.begin(), sum.end(), random) - sum.begin();
        // int n=sum.size();
        // int l=0, r=n-1;
        // int ans=0;
        // while(l<=r) {
        //     int mid = l + (r-l)/2;
        //     if(sum[mid] > random) {
        //         ans = mid;
        //         r = mid-1;
        //     } else {
        //         l = mid+1;
        //     }
        // }
        // return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */