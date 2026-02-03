class Solution {
public:

    bool dfs(TreeNode* root , int sum , int targetSum){
        if(root == nullptr) return false;
        sum += root -> val;
        if(root -> left == NULL && root -> right == NULL) return sum == targetSum;

        return dfs(root -> left , sum , targetSum) || dfs(root -> right , sum  , targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) { 
        if(root == nullptr) return false;
        return dfs(root , 0 , targetSum);
    }
};