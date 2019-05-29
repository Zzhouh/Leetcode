
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        //一定是有解的,只需要按照顺序染色即可
        //邻接
        vector<int> ret(N,0); // 0 is undefined
        vector<vector<int>> adj(N,vector<int>()); //编号是从1开始
        for(auto&e:paths){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        for(int i=0;i<N;++i){
            int a[4] = {1,1,1,1};
            for(auto&e:adj[i]){
                if(ret[e])
                    a[ret[e]-1] = 0;
            }
            for(int j=0;j<4;++j)
                if(a[j]) ret[i] = j+1;
        }
        return ret;
    }
};
