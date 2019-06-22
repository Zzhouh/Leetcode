class RLEIterator {
public:
    //二分 注意观察数据范围  总长度会溢出
    RLEIterator(vector<int>& A) {
        if(A.empty()) return;
        long cnt = 0;
        for(int i=0;i<A.size();i+=2){
            if(A[i]){//非0才加
                idx.push_back(cnt);
                cnt += A[i];
                val.push_back(A[i+1]);                
            }
        }
        s = cnt;
    }
    
    int next(int n) {
        cur += n;
        if(cur>=s || cur<0) return -1;
        auto it = std::upper_bound(idx.begin(),idx.end(),cur);
        if(it == idx.end()) return val.back();
        auto diff = it-idx.begin();
        return val[diff-1];
    }
private:
    long cur = -1;
    long s = 0;
    vector<int> val;
    vector<long> idx;
};