class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //不如一步一步走...
        int x = 0;
        int y = 0;
        int x_ = 0;
        int y_ = 0;
        int cur_dir = 0;
        int ret = 0;
        int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
        unordered_map<int,set<int>> obs_x;
        unordered_map<int,set<int>> obs_y;
        for(auto&e1:obstacles){  
            obs_x[e1[0]].insert(e1[1]);
            obs_y[e1[1]].insert(e1[0]);
        }
        for(auto cmd:commands){
            if(cmd==-2) cur_dir = (cur_dir+1)%4;
            else if(cmd==-1) cur_dir = (cur_dir+3)%4;
            else{
                x_ = x + dir[cur_dir][0]*cmd;
                y_ = y + dir[cur_dir][1]*cmd;
                
                if(cur_dir==0){
                    if(obs_x.count(x_)){
                        auto s = obs_x[x_];
                        auto iter = s.upper_bound(y);
                        if(iter==s.end()||*iter>y_) y = y_;
                        else y = *iter - 1;
                    }else
                        y = y_;
                }
                else if(cur_dir==2){
                    if(obs_x.count(x_)){
                        auto s = obs_x[x_];
                        auto iter = s.lower_bound(y_);
                        if(iter==s.end()||*iter>=y) y = y_;
                        else y = *iter + 1;
                    }else
                        y = y_;
                }
                else if(cur_dir==3){
                    if(obs_y.count(y_)){
                        auto s = obs_y[y_];
                        auto iter = s.upper_bound(x);
                        if(iter==s.end()||*iter>x_) x = x_;
                        else x = *iter - 1;
                    }else
                        x = x_;
                }
                else{
                    if(obs_y.count(y_)){
                        auto s = obs_y[y_];
                        auto iter = s.lower_bound(x_);
                        if(iter==s.end()||*iter>=x) x = x_;
                        else x = *iter + 1;
                    }else
                        x = x_;
                }
                ret = std::max(ret,x*x+y*y);
            }
        }
        return ret;
    }
};
