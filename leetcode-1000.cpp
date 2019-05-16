class Solution {
public:
//m个石头最多[(m-1)/(k-1)]堆 DP[i][j]表示 j-i+1堆合成[(j-i)/(k-1)]堆的最小cost
//状态转移为:如果i参与了合并,则合并首k个,如果i参与两次合并,则i~i+2(k-1)...
//若最终可以合并为一个,再加上所有堆的总数
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0) return -1;
        vector<int> sums(n + 1);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 1; i < n + 1; ++i) {
            sums[i] = sums[i - 1] + stones[i - 1];
        }
        for (int len = K; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
                }
                if ((j - i) % (K - 1) == 0) {
                    dp[i][j] += sums[j + 1] - sums[i];
                }
            }
        }
        return dp[0][n - 1];
    }
};

