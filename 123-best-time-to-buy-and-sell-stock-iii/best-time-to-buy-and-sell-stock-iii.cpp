class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f(int i , int lim , bool buy, vector<int>& prices){
        int n = prices.size();
        if(i == n) return 0;

        if(dp[i][lim][buy] != -1) return dp[i][lim][buy];

        int a = -1e9 , b = -1e9;
        if(buy){
            
            if(lim){
                a = f(i + 1 , lim - 1 , false , prices) -prices[i]; 
            }
            b = f(i + 1 , lim ,true , prices);
        } else{
            a = f(i + 1 , lim  , true , prices) + prices[i];
            b = f(i + 1 , lim , false , prices);
        }

        return dp[i][lim][buy] = max(a , b);

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n , vector<vector<int>> (3 , vector<int> (2 , -1)));
        return f(0 , 2 ,true , prices);
    }
};