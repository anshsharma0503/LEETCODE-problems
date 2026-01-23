class Solution {
public:
    void dfs(TreeNode* root,vector<string>& ans,string s){
        if(root==NULL) return;
        string a=to_string(root->val);
        if(root->left==NULL&&root->right==NULL){
            s+=a;
            ans.push_back(s);
            return;
        }

        dfs(root->left,ans,s+a+"->");
        dfs(root->right,ans,s+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root,ans,"");
        return ans;
    }
};