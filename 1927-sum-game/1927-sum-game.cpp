class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // Difference in number of '?' is odd
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Alice can win if she can create an unavoidable difference
        int qDiff = leftQ - rightQ;
        int sumDiff = leftSum - rightSum;

        return sumDiff != -9 * (qDiff / 2);
    }
};