class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i = 1 ; i * i <= n ; i++) v.push_back(i * i);

        vector<int> dp(n + 1  , 1e9);
        dp[0] = 0;

        for(int i = 1; i <= n ; i++){
            for(int s : v){
                if(s > i) break; 
                dp[i] = min(dp[i] , 1 + dp[i - s]);
            }
        }

        return dp[n];
    }
};