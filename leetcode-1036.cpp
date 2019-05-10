struct MyHasher {
    std::size_t operator()(const std::pair<int, int> &val) const { return val.first+val.second; }
};

//or 特化一个hash<Key>类

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        //找最大步长
        unordered_set<std::pair<int,int>,MyHasher> visited;
        unordered_set<std::pair<int,int>,MyHasher> hash;

        for(auto &e:blocked)
            hash.insert(make_pair(e[0],e[1]));

        bool flag = DFS(hash,visited,target,source[0],source[1]);
        visited.clear();
        flag &= DFS(hash,visited,source,target[0],target[1]);
        return flag;
    }
    bool DFS(unordered_set<std::pair<int,int>,MyHasher>& blocked, unordered_set<std::pair<int,int>,MyHasher>& visited, vector<int>& target, int i,int j){
        if(i>=1e6||i<0||j>=1e6||j<0||visited.count(make_pair(i,j))||blocked.count(make_pair(i,j))) return 0;
        visited.insert(make_pair(i,j));
        if(i==target[0]&&j==target[1]) return 1;
        ++step;
        if(step>MAX_STEP) return 1;//只考虑source被包围 如果还在继续dfs说明没有被包围
        if(DFS(blocked,visited,target,i+1,j)||
           DFS(blocked,visited,target,i-1,j)||
           DFS(blocked,visited,target,i,j+1)||
           DFS(blocked,visited,target,i,j-1)) return 1;
        return 0;
    }

private:
    int step = 0;
    const int MAX_STEP = 19900;
};

