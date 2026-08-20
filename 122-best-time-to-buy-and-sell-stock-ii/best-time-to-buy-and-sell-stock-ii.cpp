class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , bool buy , vector<int>& prices){
        int n = prices.size();

        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            return dp[i][buy] = max(f(i + 1 , false , prices) - prices[i] ,  f(i +1 , buy , prices));
           

        }else{
           return dp[i][buy] = max(f(i + 1 , true , prices) + prices[i] , f(i + 1 , buy , prices));
        }
        return -1;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int> (2 , -1));
        bool buy = 1;
        return f(0 , buy , prices) ;
    }
};