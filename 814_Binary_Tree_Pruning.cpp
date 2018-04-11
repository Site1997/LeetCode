/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        if ( dfs(root->left) == 0)
            root->left = NULL;
        if ( dfs(root->right) == 0)
            root->right = NULL;
        if (root->left == NULL && root->right == NULL && root->val == 0)
            return 0;
        return 1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
