class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find sum of longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Step 2: Put all numbers into a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Step 3: Find smallest missing integer >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};