class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means current player can win with i stones
        // dp[0] = false because no move is possible

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {

                // If we can move to a losing state,
                // current player wins
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};