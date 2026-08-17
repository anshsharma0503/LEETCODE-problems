class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , int j , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m - 1 && j == n -1) return grid[i][j];

        if(i == m || j == n) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(f(i + 1 , j , grid) , f(i  , j + 1, grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m , vector<int> (n , -1));
        return f(0 , 0 , grid);
    }
};