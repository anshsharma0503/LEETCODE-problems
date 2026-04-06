class Solution {
public:

    vector<vector<int>> dp;

    int f(int  i , int j , string& s1 , string& s2){
        if(i == s1.length()) return s2.length() - j;
        if(j == s2.length()) return s1.length() - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return f(i + 1 , j + 1 , s1 , s2);

        return dp[i][j] = 1 +  min(f(i + 1 , j , s1 , s2) , f(i , j + 1 , s1 , s2));
    }

    int minDistance(string word1, string word2) {
        dp.resize(word1.length() , vector<int> (word2.length() , -1));
        return f(0 , 0 , word1 , word2);
    }
};