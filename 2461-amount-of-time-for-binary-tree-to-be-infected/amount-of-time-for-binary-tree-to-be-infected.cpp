class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> par;

    TreeNode* findNode(TreeNode* root, int target) {
        if(root == NULL) return NULL;

        if(root->val == target)
            return root;

        TreeNode* leftAns = findNode(root->left, target);
        if(leftAns != NULL) return leftAns;

        return findNode(root->right, target);
    }

    void AssignPar(TreeNode* root){
        if(root == nullptr) return;

        if(root -> left) par[root -> left] = root;
        if(root -> right) par[root -> right] = root;

        AssignPar(root -> left);
        AssignPar(root -> right);
    }

    int amountOfTime(TreeNode* root, int start) {
        int time= 0;    
        unordered_set<TreeNode*> seen;
        par[root] =nullptr;
        AssignPar(root);

        TreeNode* nodeAddress = findNode(root, start);
        queue<pair<TreeNode* , int>> q;
        q.push({nodeAddress , 0});
        seen.insert(nodeAddress);

        while(q.size() > 0){
                auto node = q.front(); q.pop();
                auto p = node.first;
                auto s = node.second;

                time = max(time , s);

                if(p -> left && seen.find(p -> left) == seen.end()){
                    q.push({p -> left , s + 1 });
                    seen.insert(p -> left);
                }
                if(p -> right && seen.find(p -> right) == seen.end()){
                    q.push({p -> right , s + 1 });
                    seen.insert(p -> right);
                }
                if(par[p] && seen.find(par[p]) == seen.end()){
                    q.push({par[p] , s + 1});
                    seen.insert(par[p]);
                }
                

            
        }

        return time;

        
    }
};