class Solution {
public:
    bool isValid(vector<vector<char>>&grid,vector<vector<int>>&vis,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0)return false;
        if(r >= n || c >= m)return false; //out of bounds
        if(grid[r][c] == '1' && vis[r][c] == 0){ //valid island and not visited
            return true;
        }
        else {
            return false;
        }
    }

    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m,int row,int col){
        if(isValid(grid, vis, row, col)){
            vis[row][col] = true;
            //up
            dfs(grid,vis,n,m,row-1,col);
            // down
            dfs(grid,vis,n,m,row+1,col);
            // right
            dfs(grid,vis,n,m,row,col+1);
            //left
            dfs(grid,vis,n,m,row,col-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,false));
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid,vis,n,m,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
