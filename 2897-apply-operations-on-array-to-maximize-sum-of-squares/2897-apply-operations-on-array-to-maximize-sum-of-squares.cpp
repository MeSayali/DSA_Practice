
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        vector<int> cnt(32, 0);

        // Step 1: Count set bits
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1LL << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long val = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (cnt[bit] > 0) {
                    val |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            // Step 3: Add square modulo MOD
            ans = (ans + val * val) % MOD;
        }

        return ans;
    }
};