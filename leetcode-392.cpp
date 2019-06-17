class Solution {
public:
    bool isSubsequence(string s, string t) {
        //greedy--choose the first letter
        int cur = 0;            
        if(cur==s.size()) return true;
        for(int i=0;i<t.size();++i){
            if(t[i] == s[cur]) ++cur;
            if(cur==s.size()) return true;
        }
        return false;
    }
};