class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //snapsack
        int sum = std::accumulate(stones.begin(),stones.end(),0);
        vector<int> DP(sum/2+1,0);
        DP[0] = 1;//是否可以有一堆石头和为i
        for(auto&e:stones){     //不含第i个石头时的组合情况
            for(int i=sum/2;i>=e;--i)
                    DP[i] |= DP[i-e];
        }
        int ret = numeric_limits<int>::max();
        for(int i=0;i<=sum/2;++i)
            ret = std::min(ret,sum-DP[i]*i*2);//x2-x1=s-2*x1
        return ret;
    }
};