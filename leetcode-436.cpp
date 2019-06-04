class Solution {
public:
    //关键是left不重复
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.empty()) return vector<int>();
        vector<int> ret(intervals.size(),-1);
        unordered_map<int,int> idx;//left,idx
        vector<int> left(intervals.size());
        for(int i=0;i<intervals.size();++i){
            idx[intervals[i][0]] = i;
            left[i] = (intervals[i][0]);
        }
        std::sort(left.begin(),left.end());
        //binary search
        auto it = left.begin();
        for(auto&e:left){
            
            auto iter = std::lower_bound(it,left.end(),intervals[idx[e]][1]);
            if(iter!=left.end())
                ret[idx[e]] = idx[*iter]; 
            ++it;
        }
        
        return ret;
    }
};