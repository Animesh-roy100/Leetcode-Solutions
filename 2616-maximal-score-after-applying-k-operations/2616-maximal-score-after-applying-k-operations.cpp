class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num: nums) pq.push(num);
        long long ans=0;
        while(k--) {
            int num = pq.top();
            pq.pop();
            ans += num;
            int ceilOfNum = ceil(num/3.0);
            pq.push(ceilOfNum);
        }
        return ans;
    }
};