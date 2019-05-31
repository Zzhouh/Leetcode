class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //like viterbi?
        unordered_map<string,int> DP;
        vector<vector<int>> idx(17,vector<int>());//the idx of s with len i
        for(int i=0;i<words.size();++i){
            idx[words[i].size()].push_back(i);
            DP[words[i]] = 1;
        }
        for(int i:idx[1])
            DP[words[i]] = 1; //以此结尾的chain最大长度
        int ret = 1;
        for(int i=2;i<=16;++i){
            for(auto&sidx:idx[i]){
                string s_i = words[sidx];//长为i的字符串
                for(int j=0;j<s_i.size();++j){
                    if(DP.count(s_i.substr(0,j)+s_i.substr(j+1,s_i.size()-j))){
                        DP[s_i] = std::max(DP[s_i.substr(0,j)+s_i.substr(j+1,s_i.size()-j)]+1,DP[s_i]);
                        ret = std::max(DP[s_i],ret);
                    }
                }
            }
        }
        return ret;
    }
};