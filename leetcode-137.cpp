class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //位运算解决正负
        int ret = 0;
        int mask = 0x1;
        int cnt0=0,cnt1=0;    
        for(int i=0;i<32;++i){
            cnt1 = cnt0 = 0;
            for(auto&e:nums){
                int temp = e&0x1;
                e>>=1;
                if(temp) cnt1++;
                else ++cnt0;
            }   
            if(cnt1%3){
                ret |= mask;
            }
            if(i!=31) mask<<=1;
        }
        return ret;
    }
};
