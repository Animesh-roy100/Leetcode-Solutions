class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int ops=0;
        while(!pq.empty()) {
            int x = pq.top();
            if(x >= k) return ops;
            pq.pop();
            int y = pq.top();
            pq.pop();

            int temp = min(x, y) * 2 + max(x, y);
            pq.push(temp);
            ops++;
        }
        
        return ops;
    }
};