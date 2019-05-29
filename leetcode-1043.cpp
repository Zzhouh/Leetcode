class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        //simple dp with O(NK)
        //先写状态转移,当前之前的认为都可访问
        if(A.empty()) return 0;
        if(A.size()==1) return A[0];
        vector<int> DP(A.size()+1,0);
        for(int i=1;i<=A.size();++i){
            int max = numeric_limits<int>::min();
            for(int j=1;j<=K&&i-j>=0;++j){
                max = std::max(max,A[i-j]);
                DP[i] = std::max(DP[i],DP[i-j]+max*(j));
            }
        }
        return DP.back();
    }
};
