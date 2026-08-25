class Solution {
public:

    // vector<vector<int>> dp;

    // int lps(int i ,int j , string s){
    //     if(i == j) return 1;
    //     if(j < i) return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(s[i] == s[j]) return dp[i][j] = 2 + lps(i + 1 ,j - 1 , s);
    //     return dp[i][j] = max(lps(i + 1 , j , s) , lps(i , j - 1 , s));

    // }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp;
        string t=s;
        dp.assign(n+1, vector<int> (n+1 , 0));
        reverse(s.begin(),s.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1]==s[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n - dp[n][n];
    }
};