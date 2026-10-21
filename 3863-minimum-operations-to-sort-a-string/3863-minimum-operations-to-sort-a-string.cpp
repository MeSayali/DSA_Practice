
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end()))
            return 0;

        // Case 2: Length 2 cannot be sorted
        if (n == 2)
            return -1;

        // Find minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 3: One operation is enough
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // Case 4: Minimum or maximum is in the middle
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        // Case 5: Need three operations
        return 3;
    }
};
