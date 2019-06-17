/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node{
    long idx;
    TreeNode* root;
    node(int x,TreeNode* r){
        idx = x;
        root = r;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //level-wise
        //放到完全二叉树去做，注意初始点 否则溢出
        queue<node> q;
        long ret = 1;
        int temp = 0;
        if(!root) return 0;
        
        int cur = 1;
        q.push(node(0,root));
        while(!q.empty()){
            bool flag = 1;
            long min = numeric_limits<long>::max();
            long max = 0;
            int min_ = -1;
            int cur_next = 0;
            while(cur--){
                auto p = q.front();
                max = std::max(p.idx,max);
                min = std::min(p.idx,min);
                if(p.root->left){
                    ++cur_next;
                    if(flag){
                        flag = 0;
                        min_ = p.idx;
                        q.push(node(0,p.root->left));
                    }else{
                        q.push(node((p.idx-min_)*2,p.root->left));
                    }
                }
                if(p.root->right){
                    ++cur_next;
                    if(flag){
                        flag = 0;
                        min_ = p.idx;
                        q.push(node(1,p.root->right));
                    }else{
                        q.push(node((p.idx-min_)*2+1,p.root->right));
                    }
                }
                q.pop();
            }
            cout<<endl;
            cur = cur_next;
            if(max>=min)
                ret = std::max(ret,max-min+1);
        }
        return ret;
        
    }
};