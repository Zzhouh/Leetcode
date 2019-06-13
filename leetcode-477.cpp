class Solution {
public:
    //就是0和1的组合情况
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0;
        auto mask = 1U;
        for(int i=0;i<32;++i){
            bool stop = true;
            int cnt0 = 0;
            int cnt1 = 0;
            for(auto&ele:nums){
                if(ele&mask) ++cnt1;
                else ++cnt0;
                ele >>= 1;
                if(ele) stop = false;
            }
            ret += cnt1*cnt0;
            if(stop) return ret;
            
        }
        return ret;
    }
};