class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1 , INT_MAX - 2);
        dp[0] = 0;

        for(int i = 0 ; i <= amount ; i++){
            for(int c : coins){
                if(i - c >= 0) dp[i] = min(dp[i] , 1 + dp[i - c]);
            }
        }

        if(dp[amount] != INT_MAX - 2) return dp[amount];
         return -1;
    }
};