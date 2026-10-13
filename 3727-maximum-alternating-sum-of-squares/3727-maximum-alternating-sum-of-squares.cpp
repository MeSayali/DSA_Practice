
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) {
                 return abs(a) < abs(b);
             });

        long long score = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];

            if (i < n / 2) {
                score -= square;
            } else {
                score += square;
            }
        }

        return score;
    }
};