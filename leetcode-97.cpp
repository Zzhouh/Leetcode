class Solution {
public:
	//容易写出递归，从而不难写出状态转移
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0;
        if(s1.size()+s2.size()!=s3.size()) return 0;
        if(s1.empty()) return s2==s3;
        if(s2.empty()) return s1==s3;
        vector<vector<int>> DP(s1.size()+1,vector<int>(s2.size()+1,1));
        for(int i=1;i<=s1.size();++i)
            DP[i][0] = (s1.substr(0,i)==s3.substr(0,i));
        for(int j=1;j<=s2.size();++j)
            DP[0][j] = (s2.substr(0,j)==s3.substr(0,j));
        for(int i=1;i<=s1.size();++i){
            for(int j=1;j<=s2.size();++j){
                if(s1[i-1]!=s3[i+j-1]&&s2[j-1]!=s3[i+j-1]) DP[i][j]=0;
                else if(s1[i-1]!=s3[i+j-1]) DP[i][j] = DP[i][j-1];
                else if(s2[j-1]!=s3[i+j-1]) DP[i][j] = DP[i-1][j];
                else DP[i][j] = DP[i-1][j]||DP[i][j-1];
            }            
        }

            
        return DP[s1.size()][s2.size()];
    }
};