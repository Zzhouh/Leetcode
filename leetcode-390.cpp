class Solution {
public:
    int lastRemaining(int n) {
        //递推关系。。。
        if(n==1) return 1;
        if(n<5) return 2;
        if(n&0x1U) return lastRemaining(n-1);
        else{
            n /=2;
            int idx = lastRemaining(n/2);
            return ((n&0x1U)?(4+4*(idx-1)):(2+4*(idx-1)));
        }
    }
};