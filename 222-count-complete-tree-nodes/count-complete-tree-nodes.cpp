class Solution {
public:
    int leftht(TreeNode* root){
        int lh = 0;
        while(root){
            lh++;
            root = root -> left;
        } 

        return lh;
    }
    int rightht(TreeNode* root){
        int rh = 0;
        while(root){
            rh++;
            root = root -> right;
        } 

        return rh;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = leftht(root);
        int rh = rightht(root);

        if(lh == rh) return (1 << lh) -1;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};