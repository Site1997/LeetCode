class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int x_len = grid.size();
        int y_len = grid[0].size();
        int mx_x[x_len]; int mx_y[y_len];
        for (int i=0; i<x_len; i++) {
            int mx_num = -1;
            for (int j=0; j<y_len; j++)
                mx_num = std::max(mx_num, grid[i][j]);
            mx_x[i] = mx_num;
        }
        for (int j=0; j<y_len; j++) {
            int mx_num = -1;
            for (int i=0; i<x_len; i++)
                mx_num = std::max(mx_num, grid[i][j]);
            mx_y[j] = mx_num;
        }
        int ret = 0;
        for (int i=0; i<x_len; i++)
            for (int j=0; j<y_len; j++)
                ret += std::min(mx_x[i], mx_y[j]) - grid[i][j];
        return ret;
    }
};
