class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f(int i, int m, int n, vector<string>& strs){

        if(i == strs.size())
            return 0;

        if(dp[i][m][n] != -1)
            return dp[i][m][n];

        int zero = 0, one = 0;

        for(char ch : strs[i]){
            if(ch == '0') zero++;
            else one++;
        }

        int notTake = f(i + 1, m, n, strs);

        int take = 0;

        if(zero <= m && one <= n)
            take = 1 + f(i + 1, m - zero, n - one, strs);

        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int sz = strs.size();

        dp.resize(sz,vector<vector<int>>(m + 1,vector<int>(n + 1, -1)));

        return f(0, m, n, strs);
    }
};