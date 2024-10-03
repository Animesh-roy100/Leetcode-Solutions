class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        int n = nums.size();

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // Find the remainder when totalSum is divided by p
        int remainder = totalSum % p;
        if (remainder == 0) {
            return 0; // The sum is already divisible by p, no subarray needs to be removed
        }

        // Hash map to store the mod value of prefix sums
        unordered_map<int, int> prefixModIndex;
        prefixModIndex[0] = -1; // Handle the case where the subarray starts from the beginning
        long long prefixSum = 0;
        int minLength = n;

        // Traverse the array and calculate prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;

            // Find the target mod value that would make the remaining array sum divisible by p
            int targetMod = (prefixSum - remainder + p) % p;

            // If this targetMod was seen before, calculate the length of the subarray
            if (prefixModIndex.find(targetMod) != prefixModIndex.end()) {
                minLength = min(minLength, i - prefixModIndex[targetMod]);
            }

            // Store the current prefixSum mod p with its index
            prefixModIndex[prefixSum] = i;
        }

        // If no valid subarray is found, return -1, otherwise return the minimum length
        return (minLength == n) ? -1 : minLength;
    }
};