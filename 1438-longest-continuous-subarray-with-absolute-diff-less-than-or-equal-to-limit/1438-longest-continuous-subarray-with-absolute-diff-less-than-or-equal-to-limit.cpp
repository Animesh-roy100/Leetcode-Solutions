class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        deque<int> minq, maxq;

        while (right < n) {
            while (!minq.empty() && nums[minq.back()] >= nums[right]) {
                minq.pop_back();
            }
            minq.push_back(right);

            while (!maxq.empty() && nums[maxq.back()] <= nums[right]) {
                maxq.pop_back();
            }
            maxq.push_back(right);

            while (nums[maxq.front()] - nums[minq.front()] > limit) {
                left++;
                if (left > minq.front()) {
                    minq.pop_front();
                }
                if (left > maxq.front()) {
                    maxq.pop_front();
                }
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};