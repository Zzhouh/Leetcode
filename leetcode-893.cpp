class Solution {
public:
//sort the odd / even subseq
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for(auto&e :A)
            s.insert(helper(e));
        return s.size();
    }
    string helper(string& s){
        string s1,s2;
        for(int i=0;i<s.size();i+=2){
            s1 += s[i];
            s2 += s[i+1];
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1+s2;
    }
};
