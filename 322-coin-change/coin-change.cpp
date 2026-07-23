class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, INF));

        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            for(int amt = 1; amt <= amount; amt++) {

                int notTake = dp[i + 1][amt];

                int take = INF;

                if(coins[i] <= amt)
                    take = 1 + dp[i][amt - coins[i]];

                dp[i][amt] = min(take, notTake);
            }
        }

        return dp[0][amount] == INF ? -1 : dp[0][amount];
    }
};