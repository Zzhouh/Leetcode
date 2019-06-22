class Solution {
public:
    int numTilePossibilities(string tiles) {
        //only 7 tiles just search all combinations
        int a[26];
        memset(a,0,sizeof(int)*26);
        for(int i=0;i<tiles.size();++i)
            ++a[tiles[i]-'A'];
        DFS(0,a,tiles.size());
        return ret;
    }
    void DFS(int k,int a[],int n){
        if(k==n) return;
        for(int i=0;i<26;++i){
            if(a[i]){
                ++ret;
                --a[i];
                DFS(k+1,a,n);
                ++a[i];
            }
        }
    }
private:
    int ret = 0;
};