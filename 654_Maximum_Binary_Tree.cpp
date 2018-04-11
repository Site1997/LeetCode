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
    
    TreeNode* dfs(vector<int> nums) {
        if (nums.size() == 0)
            return NULL;
        int mxval = -1, idx = 0, sz = nums.size();
        for (int i=0; i<sz; i++) if (nums[i] > mxval) {
            mxval = nums[i];
            idx = i;
        }
        vector<int> left_nums, right_nums;
        for (int i=0; i<sz; i++) {
            if (i < idx) left_nums.push_back(nums[i]);
            if (i > idx) right_nums.push_back(nums[i]);
        }
        TreeNode *p = new TreeNode(mxval);
        p->left = dfs(left_nums);
        p->right = dfs(right_nums);
        return p;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums);
    }
};
