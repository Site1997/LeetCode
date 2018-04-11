class Solution {
public:
    void dfs (vector< vector<int> >& ans, int l, int r, vector<int> nums) {
        if (l+1 == r) {
            ans.push_back(nums);
            return ;
        }
        for (int i=l; i<r; i++) {
            swap (nums[i], nums[l]);
            dfs (ans, l+1, r, nums);
            swap (nums[i], nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        dfs (ans, 0, nums.size(), nums);
        return ans;
    }
};
