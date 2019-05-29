class Solution {
public:
    string removeDuplicates(string S) {
        //two adjacent  ---> stack(seq)
        string s;
        for(auto&ch:S){
            if(s.empty()) s.push_back(ch);
            else if(s.back()==ch) s.pop_back();
            else s.push_back(ch);
        }
            return s;
        }
};
