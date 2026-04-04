class Solution {
public:

    vector<vector<int>> dp;
    int f(int i , int j , string s1 , string s2){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return f(i - 1 , j - 1 , s1 , s2);

        return dp[i][j] = min({ 1 + f(i , j - 1 , s1  ,s2) , 1 + f(i - 1 , j , s1 , s2) ,
         1 + f(i - 1 , j - 1 , s1 , s2)});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        dp.resize(n , vector<int> (m , -1));
        return f(n - 1 , m - 1 ,word1 , word2);
    }
};