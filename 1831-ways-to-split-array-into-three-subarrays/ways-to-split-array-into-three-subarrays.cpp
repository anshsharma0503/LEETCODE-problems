class Solution {
public:
    int waysToSplit(vector<int>& nums) {

        const int MOD = 1e9 + 7;

        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {

            int low = i + 1;
            int high = n - 2;
            int first = -1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                long long left = pre[i + 1];
                long long middle = pre[mid + 1] - pre[i + 1];

                if (left <= middle) {
                    first = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            low = i + 1;
            high = n - 2;
            int last = -1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                long long middle = pre[mid + 1] - pre[i + 1];
                long long right = pre[n] - pre[mid + 1];

                if (middle <= right) {
                    last = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (first != -1 && last != -1 && first <= last)
                ans = (ans + (last - first + 1)) % MOD;
        }

        return ans;
    }
};