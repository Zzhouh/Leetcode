class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //use stack
        //unfold circle
        if(nums.empty()) return nums;
        vector<int> ret(nums.size(),-1);
        stack<int> s;
        s.push(0);
        for(int i=1;i<2*nums.size();++i){
            while(!s.empty()&&nums[i%nums.size()]>nums[s.top()]){
                ret[s.top()] = nums[i%nums.size()];
                s.pop();
            }
            if(i<nums.size()) s.push(i);
        }
        return ret;
    }
};
