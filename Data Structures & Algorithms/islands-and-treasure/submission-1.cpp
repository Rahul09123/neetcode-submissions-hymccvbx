class Solution {
public:
    int INF = INT_MAX;  

    void dfs(vector<vector<int>>& grid,int row, int col,int n,int m,int dist){
        if(row < 0 || col < 0 || row >= n || col >= m)return;
        if(grid[row][col] == -1)return;
        if(grid[row][col] < dist)return;
        grid[row][col] = dist;
        dfs(grid,row+1,col,n,m,dist+1);
        dfs(grid,row-1,col,n,m,dist+1);
        dfs(grid,row,col+1,n,m,dist+1);
        dfs(grid,row,col-1,n,m,dist+1);
        
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == 0){
                    dfs(grid,i,j,n,m,0);
                }
            }
        }

    }
};
