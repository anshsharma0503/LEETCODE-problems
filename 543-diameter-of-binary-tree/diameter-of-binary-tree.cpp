class Solution {
public:

    int max_ht;

    int f(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = f(root -> left);
        int rh = f(root -> right);

        int ht = max(lh , rh) + 1;
        max_ht = max(max_ht , lh + rh);

        return ht;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        max_ht = 0;
        f(root);
        return max_ht;
        
    }
};