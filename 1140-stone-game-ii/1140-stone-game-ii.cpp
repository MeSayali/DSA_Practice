class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // If all piles are taken
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Current player can take X piles, where X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            // Stones taken by current player
            int taken = suffix[i] - suffix[i + X];

            // Stones opponent can get after our move
            int opponent = solve(i + X, max(M, X));

            // Current player's total =
            // stones taken now + stones remaining after opponent
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(2 * n + 1, -1));

        return solve(0, 1);
    }
};