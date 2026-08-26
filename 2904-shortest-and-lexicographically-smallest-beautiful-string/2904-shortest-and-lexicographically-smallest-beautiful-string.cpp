class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // If we have more than k ones, move left
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                // Remove leading zeros because they are unnecessary
                while (left <= right && s[left] == '0') {
                    left++;
                }

                string curr = s.substr(left, right - left + 1);

                // Update if:
                // 1. curr is shorter, OR
                // 2. same length but curr is lexicographically smaller
                if (ans.empty() ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};