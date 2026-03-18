class Solution {
public:
    int maxi;
    vector<vector<vector<int>>> dp;

    int f(int i  ,  vector<string>& strs, int m, int n){
        if(i == strs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zerocnt = 0 , onecnt =0;
        for(auto x : strs[i]){
            if(x == '0') zerocnt++;
            else onecnt++;
        }
        int take = 0;

        if(zerocnt <= m && onecnt <= n)  take = 1 + f(i + 1  , strs , m- zerocnt , n - onecnt);
        
        int nottake = f(i + 1 , strs , m , n);
        
        return dp[i][m][n] =max(take, nottake);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        dp.resize(strs.size() , vector<vector<int>> (m + 1, vector<int> (n + 1 , -1)));
        return f(0 , strs , m , n);
    }
};