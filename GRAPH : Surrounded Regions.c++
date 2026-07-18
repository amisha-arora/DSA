class Solution {

public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delrow[], int delcol[]){
        // wrote delrow instead of delrow[]
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                // didnt wrote 0 checking condition
                dfs(nrow,ncol,board,vis,delrow,delcol);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i <m;i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,board,vis,delrow,delcol);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1,i,board,vis,delrow,delcol);
            }
        }
        for(int i = 0 ; i <n;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis,delrow,delcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }
        for(int i = 0 ; i < n;i++){
            for(int j = 0; j < m ;j++){// wrote i here 
                if(!vis[i][j] && board[i][j] == 'O'){
                    // wrote == sign
                    board[i][j] = 'X';
                }
            }
        }
    }
};
