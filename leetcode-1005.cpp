class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        //1. negative 2 positive
        //2. sub the smallest
        sort(A.begin(),A.end());
        int min_ = numeric_limits<int>::max();
        int num_neg = 0;
        for(int i=0;i<A.size();++i){
            if(A[i]<0 && num_neg<K) {
                A[i] = -A[i];
                ++ num_neg;
            }
            min_ = std::min(min_,A[i]);
        }
        int ret = std::accumulate(A.begin(),A.end(),0);
        if(num_neg<K && (K-num_neg)%2) ret -= 2*min_;
        return ret;
    }
};