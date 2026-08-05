class Solution {
public:

    int nextNumber(int n)
    {
        int sum = 0;

        while(n)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> visited;

        while(n != 1)
        {
            if(visited.count(n))
                return false;

            visited.insert(n);

            n = nextNumber(n);
        }

        return true;
    }
};
