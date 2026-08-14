class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            // If any character appears more than twice,
            // shrink the window from the left.
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};