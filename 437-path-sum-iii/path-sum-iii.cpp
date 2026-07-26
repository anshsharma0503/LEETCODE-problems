class Solution {
public:
    unordered_map<long long, int> prefix;
    int ans = 0;

    void dfs(TreeNode* root, long long curr, int target) {

        if (root == nullptr)
            return;

        curr += root->val;

        ans += prefix[curr - target];

        prefix[curr]++;

        dfs(root->left, curr, target);
        dfs(root->right, curr, target);

        prefix[curr]--;
    }

    int pathSum(TreeNode* root, int targetSum) {

        prefix[0] = 1;

        dfs(root, 0, targetSum);

        return ans;
    }
};