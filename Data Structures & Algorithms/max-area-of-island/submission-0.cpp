class Solution {
public:
    bool isValid(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0)return false;
        if(row >= n || col >= m)return false;
        if(grid[row][col] == 1 && vis[row][col] == 0){
            return true;
        }
        else return false;
    }

    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m,int row,int col,int& cnt){
        if(isValid(grid,vis,row,col)){
            vis[row][col] = true;
            cnt++;
            dfs(grid,vis,n,m,row+1,col,cnt);
            dfs(grid,vis,n,m,row-1,col,cnt);
            dfs(grid,vis,n,m,row,col-1,cnt);
            dfs(grid,vis,n,m,row,col+1,cnt);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,false));
        int ans = 0;
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int cnt = 0;
                    dfs(grid,vis,n,m,i,j,cnt);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};