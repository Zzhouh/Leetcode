class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int x = 0;
        int s = arr.size();
        int j = s-1;
        int i = 0;
        bool dup_tail = 0;
        while(i<j){
            if(arr[i]==0){
                --j;
                if(i==j) dup_tail = 1;
            }
            ++i;
        }
        i = s-1;
        for(int k=j;k>=0&&i>=0;--k){
            arr[i--] = arr[k];
            if(arr[k]==0){
                if(k==j){
                    if(dup_tail) arr[i--] = 0;
                }
                else arr[i--] = 0;
            }
        }
        
    }
};