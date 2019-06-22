class Solution {
public:
    //bfs to solve the shortest
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if(grid[0][0]||grid[N-1][N-1]) return -1;
        if(grid.size()==1) return 1;
        vector<vector<int>> visited(grid.size(),vector<int>(grid.size(),0));
        queue<pair<int,int>> bf;
        bf.push(make_pair(0,0));
        int cur = 1;
        while(!bf.empty()){
            ++ret;
            cur_next = 0;
            while(cur--){
                auto pr = bf.front();
                bf.pop();
                if(pr.first==N-1&&pr.second==N-1) return ret; 
                traverse8(pr,grid,visited,bf);
            }
            cur = cur_next;
        }
        return -1;
        
    }
    void traverse8(pair<int,int>& pr,vector<vector<int>>& grid,vector<vector<int>>& visited,queue<pair<int,int>>& bf){

        for(int i=0;i<8;++i){
            int x = pr.first + dir[i][0];
            int y = pr.second + dir[i][1];
            if(inbound(grid.size(),x,y)&&!grid[x][y]&&!visited[x][y]){
                bf.push(make_pair(x,y));
                visited[x][y] = 1;
                ++cur_next;
            }
        }
    }
    
    bool inbound(int N,int x,int y){
        return (x>=0)&&(x<N)&&(y>=0)&&(y<N);
    }
    
private:
    int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    int ret = 0; 
    int cur_next = 0;
};