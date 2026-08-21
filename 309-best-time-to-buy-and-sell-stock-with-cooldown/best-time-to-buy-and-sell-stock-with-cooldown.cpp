class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , bool buy , vector<int>& prices){
        int n = prices.size();

        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy)
            return dp[i][buy] = max(f(i + 1 , false , prices) - prices[i] , f(i + 1 , true , prices));
        else 
            return dp[i][buy] = max(f(i + 2 , true , prices) + prices[i] , f(i + 1 , false , prices));
    }

    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() , vector<int> (2 , -1));
        return f(0 , true , prices);
    }
};