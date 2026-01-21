class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root == nullptr || helper(root -> left , root -> right));
    }

    bool helper(TreeNode* l , TreeNode* r){
        if(l == nullptr || r == nullptr) return l == r;

        if(l -> val != r -> val) return false;

        return helper(l -> right , r -> left) && helper(l -> left , r -> right);
    }
};