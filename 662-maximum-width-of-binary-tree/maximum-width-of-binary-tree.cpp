class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long>> q;
        unsigned long long max_width = 0;

        q.push({root , 1});

        while(q.size() > 0){
             unsigned long long st_idx = q.front().second;
             unsigned long long end_idx = q.back().second;
            unsigned long long width = end_idx - st_idx + 1;

            max_width = max(max_width , width);

            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                auto x = q.front(); q.pop();
                TreeNode* node = x.first;
               unsigned long long idx = x.second;
                if(node -> left) q.push({node -> left , idx * 2});
                if(node -> right) q.push({node -> right , idx * 2 + 1});
            }
        }

        return max_width;
    }
};