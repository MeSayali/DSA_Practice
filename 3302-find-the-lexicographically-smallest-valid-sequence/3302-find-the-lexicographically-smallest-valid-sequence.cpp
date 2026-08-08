class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[j] = earliest index in word1 from which
        // word2[j...m-1] can be matched exactly
        vector<int> suf(m);

        int i = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) {
                i--;
            }

            if (i < 0) {
                suf[j] = -1;
            } else {
                suf[j] = i;
                i--;
            }
        }

        vector<int> ans;
        int j = 0;
        bool changed = false;

        for (i = 0; i < n && j < m; i++) {

            // Normal matching
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!changed) {

                // Need word2[j+1 ... m-1] to be
                // matched exactly after index i.
                if (j == m - 1 || 
                    (suf[j + 1] != -1 && i < suf[j + 1])) {

                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};