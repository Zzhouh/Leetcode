
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        //DFS 可以用二进制表示子集,存储每个子集是否可以组成边长
        //然后使用位运算 进行DP 4个集合->2+2->1+1+1+1
        sort(nums.begin(),nums.end());
        int sum = std::accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<4||sum%4||nums.back()>sum/4) return false;
        if(sum==0&&nums.size()>=4) return true;
        return helper(nums,0,sum/4);
    }

    bool helper(vector<int>& nums,int i,int target){

        if(i==nums.size()){
            return (s[0]==s[1])&&(s[1]==s[2])&&(s[2]==s[3])&&(s[3]==target);
        }

        //剪枝
        for(int k=0;k<4;++k)
            if(s[k]+nums[i]>target&&s[k]!=target) return false;//后面也不可能了 不必再搜索后续元素的分配方式

        for(int k=0;k<4;++k){
                //try
            int j = k;
            while (--j >= 0) // third
                if (s[i] == s[j])
                    break;
            if (j != -1) continue; //注意DFS的执行过程 到第k个集合的话 是第i个元素放到0~k-1个集合都不可能产生正确解 由等价性

            if(s[k]+nums[i]<=target){
                s[k] += nums[i];
                if(helper(nums,i+1,target)) return true;
                s[k] -= nums[i]; //因为已经排序
            }
        }
        return false;


    }

private:
    int s[4] = {0,0,0,0};
};
