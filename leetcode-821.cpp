class Solution {
public:
//记录C出现的idx,并且在左右加入一个head tail idx,从而每一个非C字符落入某个区间,距离为到两端的最小值
    vector<int> shortestToChar(string S, char C) {
        vector<int> idx;
        vector<int> ret(S.size(),0);
        idx.push_back(-40000);
        for(int i=0;i<S.size();++i)
            if(S[i]==C) idx.push_back(i);
        idx.push_back(40000);
        int idx_ = 1;
        for(int i=0;i<S.size();++i){
            if(i>idx[idx_]) ++idx_;
            if(i<idx[idx_]) ret[i] = std::min(i-idx[idx_-1],idx[idx_]-i);
        }
        return ret;
    }
};
