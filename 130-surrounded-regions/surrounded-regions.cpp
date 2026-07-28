class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        if (board[r][c] != 'O')
            return;

        board[r][c] = '#';

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            dfs(nr, nc, board);
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};