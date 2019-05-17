class Solution {
public:
    //有首元素 无首元素
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = std::accumulate(nums.cbegin(),nums.cend(),0);
        if(sum<S) return 0;
        if((sum-S)&0x1) return 0;
        //-----
        int target = (sum - S)/2;
        vector<vector<int>> DP(target+1,vector<int>(nums.size(),0));
        int cnt = 1;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]==0){
                cnt *= 2;
            }
            DP[0][i] = (cnt);
        }
        for(int i=1;i<=target;++i){
            for(int j=nums.size()-1;j>=0;--j){
                if(j+1==nums.size()) DP[i][j] = (i==nums[j]);
                else if(i<nums[j]) DP[i][j] = DP[i][j+1];
                else DP[i][j] = DP[i-nums[j]][j+1]+DP[i][j+1];//j到结尾和为i的方案
            }
        }
        return DP[target][0];
    }
};
