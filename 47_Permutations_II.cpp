class Solution {
public:
    void dfs (vector< vector<int> >& ans, int l, int r, vector<int> nums) {
        if (l+1 == r) {
            ans.push_back(nums);
            return ;
        }
        for (int i=l; i<r; i++) {
            if (nums[i] == nums[l] && i != l)
                continue ;
            swap (nums[i], nums[l]);
            dfs (ans, l+1, r, nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        vector< vector<int> > ans;
        dfs (ans, 0, nums.size(), nums);
        return ans;
    }
};
