class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //并查集，如果某条边的两个顶点已经属于同一个集合
        vector<int> u(edges.size()+1,0);
        for(int i=0;i<u.size();++i) u[i] = i;
        for(auto& e:edges){
            if(find_p(e[0],u)==find_p(e[1],u)) return e;
            u[find_p(e[0],u)] = e[1];
        }
        return vector<int>();

    }
    int find_p(int x,vector<int>& u){
        while(u[x]!=x)
            x = u[x];
        return x;

    }
};
