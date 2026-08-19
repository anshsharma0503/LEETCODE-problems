class Solution {
public:
    vector<vector<int>> dp;
    int f(int i , int j ,  vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m || j == n)
            return 1e9;
    
        if (i == m-1 && j == n-1)
            return max(1, 1 - grid[i][j]);

        if(dp[i][j] != -1) return dp[i][j];

        int right = f(i , j + 1 ,  grid);
        int down = f(i + 1 , j , grid);

        int next = min(right , down);

        return dp[i][j] = max(1 , next - grid[i][j]);

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        dp.assign(m, vector<int>(n, -1));
        return f(0 , 0 , dungeon);
    }
};