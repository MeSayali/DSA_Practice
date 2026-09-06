class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark numbers that are present
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            int index = x - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Find missing numbers
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};