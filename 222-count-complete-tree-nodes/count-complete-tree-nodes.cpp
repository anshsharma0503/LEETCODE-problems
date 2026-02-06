class Solution {
public:
    int res;

    void dfs(TreeNode* root){
        if(root == nullptr) return;
        res++;
        dfs(root -> left);
        dfs(root -> right);
    }

    int countNodes(TreeNode* root) {
        res = 0;
        dfs(root);

        return res;
    }
};