class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If there are no stones with remainder 1 or 2,
        // Alice cannot make a safe first move.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If number of remainder-0 stones is even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If number of remainder-0 stones is odd,
        // Alice needs one remainder type to have at least
        // two more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};