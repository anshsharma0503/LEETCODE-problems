class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , int amount, vector<int>& coins) {
        if(amount == 0) return 1;

        if(i >= coins.size()) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int nottake = f(i + 1 , amount , coins);

        int take = 0;
        if(amount - coins[i] >= 0) take = f(i , amount - coins[i] , coins);

        return dp[i][amount]= take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size() , vector<int> (amount + 1 , -1));
        return f(0 , amount , coins);
    }
};