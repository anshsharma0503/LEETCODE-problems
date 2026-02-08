class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return 1 + max(maxDepth(root -> left) , maxDepth(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        

        if(abs(left - right) > 1) return false;

        return (isBalanced(root -> left) && isBalanced(root -> right));

        
       

        }
};