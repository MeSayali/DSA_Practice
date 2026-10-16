class Solution {
    static const int MOD = 1000000007;

    class SegmentTree {
        int n;
        vector<long long> sum, sqSum, lazy;

        void apply(int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sqSum[node] = (sqSum[node]
                + 2 * val * sum[node] % MOD
                + val * val % MOD * len % MOD) % MOD;

            sum[node] = (sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r)
                return;

            int mid = (l + r) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sqSum[node] = (sqSum[node * 2] + sqSum[node * 2 + 1]) % MOD;
        }

    public:
        SegmentTree(int size) {
            n = size;
            sum.assign(4 * n, 0);
            sqSum.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void update(int l, int r) {
            if (l <= r)
                update(1, 0, n - 1, l, r);
        }

        long long getSquareSum() {
            return sqSum[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(100001, -1);

        SegmentTree tree(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last[nums[i]] + 1;

            tree.update(left, i);

            last[nums[i]] = i;

            ans = (ans + tree.getSquareSum()) % MOD;
        }

        return (int)ans;
    }
};