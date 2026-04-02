class Solution {
public:
    bool isValid(vector<vector<char>>& board,vector<vector<bool>>&vis,int n,int m,int row, int col){
        if(row < 0 || col < 0)return false;
        if(row >= n || col >= m)return false;
        if(board[row][col]=='O' && !vis[row][col]){
            return true;
        }
        else return false;
    }
    void dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,int n,int m,int row, int col){
        if(isValid(board,vis,n,m,row,col)){
            vis[row][col] = true;
            dfs(board,vis,n,m,row+1,col);
            dfs(board,vis,n,m,row-1,col);
            dfs(board,vis,n,m,row,col+1);
            dfs(board,vis,n,m,row,col-1);
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        //false -> 'X' , true-> don't change
        for(int i = 0 ;i < n; i++){
            //left column
            dfs(board,vis,n,m,i,0);
            //right column
            dfs(board,vis,n,m,i,m-1);
        }
        for(int j = 1 ; j< m ;j++){
            //top row
            dfs(board,vis,n,m,0,j);
            //bottom row
            dfs(board,vis,n,m,n-1,j);
        }
        for(int i = 0 ;i <  n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(vis[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
