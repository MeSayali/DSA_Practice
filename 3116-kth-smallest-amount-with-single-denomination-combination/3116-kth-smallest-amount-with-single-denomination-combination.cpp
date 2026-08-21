class Solution {
public:
    using ll = long long;

    long long countWays(ll x, vector<int>& coins) {
        ll count = 0;

        // Inclusion-Exclusion
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            ll lcm = 1;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    ll g = gcd(lcm, (ll)coins[i]);
                    
                    // Prevent overflow
                    ll val = lcm / g;
                    if (val > x / coins[i]) {
                        overflow = true;
                        break;
                    }

                    lcm = val * coins[i];
                }
            }

            if (overflow || lcm > x)
                continue;

            if (__builtin_popcount(mask) & 1)
                count += x / lcm;
            else
                count -= x / lcm;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll low = 1;
        ll high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (countWays(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};