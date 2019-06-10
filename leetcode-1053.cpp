class Solution {
public:
//题意是 找到交换一次的最大的小于A的排列
    vector<int> prevPermOpt1(vector<int>& A) {
        //just find the last one
        if(A.size()<2) return A;
        int idx = -1;
        for(int i=A.size()-2;i>=0;--i){
            if(A[i+1]<A[i]){
                idx = i;
                break;
            }
        }
        if(idx==-1) return A;
        int idx2 = -1;
        for(int i=A.size()-1;i>idx;--i){
            if(A[i]<A[idx]){
                idx2 = i;
                break;
            }
        }
        int idx3 = -1;
        for(int i=idx2;i>idx+1;--i){
            if(A[i]!=A[i-1]){
                idx3 = i;
                break;
            }
        }
        if(idx3==-1) idx3 = idx+1;
        
        std::swap(A[idx3],A[idx]);
        /*
        for(int i=idx+1;i<A.size();++i){
            //reverse
            if(ret[i]!=ret[A.size()-1-(i-idx-1)]) return A;
        }
        */
        return A;
    }
};