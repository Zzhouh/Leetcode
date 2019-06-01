class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //rb t
        //如果区间内有重复元素 那么已经可以返回
        //O(nlgk)
        //long 
        if(k<1||t<0) return false;
        set<long> rbt;
        for(int i=0;i<nums.size()&&i<=k;++i){
            if(rbt.count(nums[i])) return true;
            else rbt.insert(nums[i]);
        }
        auto iter = rbt.begin();
        auto iter_next = iter;
        ++iter_next;
        while(iter_next!=rbt.end()){
            if(abs(*iter_next-*iter)<=t) return true;
            ++iter;
            ++iter_next;
        }
        for(int i=k+1;i<nums.size();++i){
            rbt.erase(nums[i-k-1]);
            if(rbt.count(nums[i])) return true;
            auto iter = rbt.insert(nums[i]).first; //ret is pair(iter,bool)
            auto iter_prev = (iter);
            auto iter_next = (iter);
            ++iter_next;
            --iter_prev;
            if(iter_next!=rbt.end()&&abs(*iter_next-*iter)<=t) return true;
            if(iter!=rbt.begin()&&abs(*iter_prev-*iter)<=t) return true;
        }
        return false;
        
    }
};