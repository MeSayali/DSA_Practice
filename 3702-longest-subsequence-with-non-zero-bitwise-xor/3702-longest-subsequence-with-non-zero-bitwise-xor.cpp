class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            x ^= num;
            if (num != 0)
                hasNonZero = true;
        }

        if (x != 0)
            return n;

        if (hasNonZero)
            return n - 1;

        return 0;
    }
};