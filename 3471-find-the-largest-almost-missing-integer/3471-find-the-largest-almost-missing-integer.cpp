class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;

            // Store distinct elements of this subarray
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Count how many subarrays contain each element
            for (int x : seen) {
                count[x]++;
            }
        }

        int ans = -1;

        // Find the largest element present in exactly one subarray
        for (auto& [x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};