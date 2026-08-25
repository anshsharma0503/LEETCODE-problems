class Solution {
public:

    vector<vector<int>> dp ;

    bool f(int i , int  j ,string s1, string s2, string s3){
        int n = s1.length() , m = s2.length();
        int N= s3.length();

        if(i == n && j == m && n + m >= N) 
            return true;

        if( i < n && j < m && dp[i][j] != -1) return dp[i][j];

        int k = i + j;
        bool a = false , b = false;

        if(i < n && s1[i] == s3[k])
            a = f(i + 1 , j , s1 , s2 , s3);

        if(j < m && s2[j] == s3[k])
            b = f(i, j + 1, s1 , s2 , s3);
        
        if(i < n && j < m)
            return  dp[i][j] = a || b;
        return a|| b;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length() , m = s2.length();
        dp.assign(n , vector<int> (m , -1));
        return f(0 , 0 , s1 , s2 , s3);
    }
};