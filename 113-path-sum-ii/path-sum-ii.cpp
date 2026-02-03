class Solution {
public:

    void dfs(TreeNode* root ,vector<vector<int>>& ans ,vector<int> &a ,int sum , int targetSum){
        if(root == nullptr) return ;
        a.push_back(root -> val);
        sum += root -> val;

        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                ans.push_back(a);
            }
        }

        dfs(root -> left , ans , a , sum , targetSum);
        dfs(root -> right , ans , a , sum , targetSum);

        a.pop_back();

    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> a;
        int sum = 0;

        dfs(root , ans , a , sum,  targetSum);
        return ans;
    }
};