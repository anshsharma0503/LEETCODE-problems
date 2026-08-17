class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n , vector<int> (n , 0));

        for(int i = 0 ;i < n ; i++)
            dp[0][i] = matrix[0][i];

        for(int i = 1 ;i < n ; i++){
            for(int j = 0 ;j < n ; j++){
                int mini = dp[i - 1][j];
                if(j > 0)
                    mini = min(mini , dp[i - 1][j - 1]);

                if(j < n - 1)
                    mini = min(mini , dp[i - 1][j + 1]);

                dp[i][j] = matrix[i][j] + mini;

            }
        }

        int res = 1e9;
        for(int i = 0 ; i <n ; i++)
            res = min(res , dp[n - 1][i]);

        return res;
    }
};