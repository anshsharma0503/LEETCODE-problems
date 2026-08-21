class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , int j , string &word1, string &word2){
        int n = word1.length();
        int m = word2.length(); 

        if(i == n && j!= m) return m-j;
        if(j == m && i != n) return n - i;

        if(i == n && j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return f(i + 1 , j + 1 , word1 , word2);

        int insert = f(i , j + 1 , word1 , word2);
        int del = f(i+1 , j  , word1 , word2);
        int replace = f(i + 1 , j + 1 , word1 , word2);

        return dp[i][j] = 1 + min({insert , del , replace});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length(); 
        dp.assign(n , vector<int> (m ,-1));
        return f(0 , 0 , word1 , word2);
    }
};