class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , int j ,vector<vector<int>>& d){
        int m  =d.size();
        int n = d[0].size();
        if(i >= m || j >= n) return 1e9;

        if(dp[j][i] != -1) return dp[j][i];
 
        if(i == m - 1 && j == n - 1) return max(1 , 1- d[i][j]);

        int req = min(f(i + 1 , j , d) , f(i , j + 1 , d));

        return dp[j][i] = max(1 , req - d[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m  =dungeon.size();
        int n = dungeon[0].size();
        dp.resize(n , vector<int> (m , -1));
        return f(0 , 0 , dungeon);
    }
};