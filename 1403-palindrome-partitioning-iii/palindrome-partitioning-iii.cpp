class Solution {
public:

    int n;
    vector<vector<int>> cost;
    vector<vector<int>> dp;

    int f(int i, int k, string &s) {

        if (i == n && k == 0)
            return 0;

        if (i == n || k == 0)
            return 1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = 1e9;

        for (int j = i; j <= n - k; j++) {

            ans = min(ans, cost[i][j] + f(j + 1, k - 1, s));
        }

        return dp[i][k] = ans;
    }

    int palindromePartition(string s, int k) {

        n = s.size();

        cost.resize(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len == 2)
                        cost[i][j] = 0;
                    else
                        cost[i][j] = cost[i + 1][j - 1];

                } else {

                    if (len == 2)
                        cost[i][j] = 1;
                    else
                        cost[i][j] = 1 + cost[i + 1][j - 1];
                }
            }
        }

        dp.resize(n + 1, vector<int>(k + 1, -1));

        return f(0, k, s);
    }
};