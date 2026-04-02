class Solution {
public:

    bool isValid(vector<vector<int>>& grid,vector<vector<bool>>&vis,int row,int col){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0)return false;
        if(row >= n || col >= m)return false;
        if(grid[row][col] == 1 && vis[row][col] == false){
            return true;
        }
        else return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int fresh = 0;
        //push all the rotten oranges
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = true;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0)return 0;
        int time = 0;
        vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};

        while(!q.empty()){
            int size = q.size();
            bool spread = false;
            for(int i = 0 ;i < size ;i++){
                auto [r , c] = q.front();
                q.pop();
                for(auto [dr,dc] : dir){
                    int row = r + dr;
                    int col = c + dc;
                    if(isValid(grid,vis,row,col)){
                        q.push({row,col});
                        spread = true;
                        grid[row][col] = 2;
                        fresh--;
                        vis[row][col] = true;
                    }
                }
            }
               if(spread)time++;

        }
        if(fresh > 0)return -1;
        else return time;
    }
};
