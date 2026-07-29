class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            int ans = 0;
            int mx = 0;

            for (int j = i; j < min(n, i + k); j++) {

                mx = max(mx, arr[j]);

                int len = j - i + 1;

                ans = max(ans, mx * len + dp[j + 1]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};