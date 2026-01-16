class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        int temp = 1;
        queue<TreeNode* > q;
        q.push(root);

        while(q.size() > 0){
            int n = q.size();
            vector<int> a;

            for(int i = 0 ; i < n ; i ++){
                TreeNode* node = q.front();
                q.pop();

                a.push_back(node -> val);

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            if(temp) {
                ans.push_back(a);
                temp = 0;
            }
            else{
                reverse(a.begin() , a.end());
                ans.push_back(a);
                temp = 1;
            }
        }

        return ans;
    }
};