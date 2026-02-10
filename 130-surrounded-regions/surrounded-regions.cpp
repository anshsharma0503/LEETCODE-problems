class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m , vector<int> (n , 0));

        queue<pair<int , int>> q;

for(int i = 0; i < m; i++) {

    if(board[i][0] == 'O') {
        q.push({i, 0});
        vis[i][0] = 1;
    }

    if(board[i][n - 1] == 'O') {
        q.push({i, n - 1});
        vis[i][n - 1] = 1;
    }
}

for(int j = 0; j < n; j++) {

    if(board[0][j] == 'O') {
        q.push({0, j});
        vis[0][j] = 1;
    }

    if(board[m - 1][j] == 'O') {
        q.push({m - 1, j});
        vis[m - 1][j] = 1;
    }
}


        int dx[4] = {1 , -1 , 0 , 0};
        int dy[4] = {0 , 0 , 1 , -1};

        while(!q.empty()){
            auto[ro,col] = q.front();
            q.pop();

            for(int d = 0 ; d < 4 ; d++){
                int nro = ro + dx[d];
                int ncol = col + dy[d];

                if(nro >= 0 && ncol >= 0 && nro < m && ncol < n && vis[nro][ncol] == 0 && board[nro][ncol] == 'O'){
                    q.push({nro , ncol});
                    vis[nro][ncol] = 1;
                    board[nro][ncol] = '#';
                }
            }
        }

        for(int i = 1 ; i <= m - 2 ; i++){
            for(int j = 1 ; j <= n - 2 ; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};