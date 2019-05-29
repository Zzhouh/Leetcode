class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //O(nlgn) 用红黑树 multiset
        if(stones.size()==1) return stones[0];
        int temp = 0;
        int x,y;
        multiset<int> rbt;
        for(auto& e:stones)
            rbt.insert(e);
        while(1){
            auto iter = rbt.end();
            --iter;
            x = *iter;
            --iter;
            y = *iter;
            temp = abs(x-y);
            rbt.erase(iter,rbt.end());
            if(rbt.empty()) return temp;
            else if(rbt.size()==1&&temp==0) return *rbt.begin();
            else rbt.insert(temp);
        }

    }
};
