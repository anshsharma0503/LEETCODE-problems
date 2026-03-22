class Solution {
public:
    vector<vector<int>> dp;

    int f( int i,int amount , vector<int>& coins){ 
        if(amount == 0) return 0;
        if(i >= coins.size() ) return INT_MAX - 5;

        if(dp[i][amount] != -1) return dp[i][amount];

        int notTake = f(i + 1 , amount , coins);

        int take = INT_MAX - 5;
         if(amount - coins[i] >= 0) take = 1 + f(i  , amount - coins[i] , coins);

        return dp[i][amount] = min(take , notTake);

    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size() , vector<int> (1 + amount , -1));
        int x =  f(0, amount , coins);

        if(x == INT_MAX - 5) return -1;
        return x;
  
     }
};