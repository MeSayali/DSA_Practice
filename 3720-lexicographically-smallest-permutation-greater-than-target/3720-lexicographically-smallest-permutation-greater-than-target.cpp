class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Build answer while trying to stay equal to target
        string ans;

        for (int i = 0; i < n; i++) {

            // Try to put target[i] exactly
            if (freq[target[i] - 'a'] > 0) {
                ans += target[i];
                freq[target[i] - 'a']--;
                continue;
            }

            // target[i] is not available.
            // We need to make the current character greater
            // than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    // Put remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }

            // No greater character available at this position.
            // We need to go back and change an earlier position.
            break;
        }

        /*
         * The prefix matched target as much as possible.
         * Now try to increase the rightmost position.
         */
        freq.assign(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Try every position from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Characters used by target[0...i-1]
            bool possible = true;

            vector<int> remaining = freq;

            for (int j = 0; j < i; j++) {
                if (remaining[target[j] - 'a'] == 0) {
                    possible = false;
                    break;
                }
                remaining[target[j] - 'a']--;
            }

            if (!possible)
                continue;

            // At position i, find smallest character > target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (remaining[c] > 0) {

                    string result = target.substr(0, i);
                    result += char('a' + c);
                    remaining[c]--;

                    // Add remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (remaining[x] > 0) {
                            result += char('a' + x);
                            remaining[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};