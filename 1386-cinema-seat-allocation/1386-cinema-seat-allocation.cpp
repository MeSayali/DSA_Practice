class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Only seats 2 to 9 matter
            if (s >= 2 && s <= 9) {
                rows[row] |= (1 << s);
            }
        }

        // Initially, every row can fit 2 groups
        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {
            bool left  = true;  // seats 2-5
            bool middle = true; // seats 4-7
            bool right = true;  // seats 6-9

            // Check seats 2-5
            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << s)) {
                    left = false;
                }
            }

            // Check seats 4-7
            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << s)) {
                    middle = false;
                }
            }

            // Check seats 6-9
            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << s)) {
                    right = false;
                }
            }

            if (left && right) {
                // Two non-overlapping groups
                ans += 2;
            }
            else if (left || middle || right) {
                // Only one group can fit
                ans += 1;
            }
        }

        return ans;
    }
};