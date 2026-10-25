class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        function<bool(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n)
                return false;

            if (grid[r][c] == 1)
                return true;

            grid[r][c] = 1;

            bool a = dfs(r - 1, c);
            bool b = dfs(r + 1, c);
            bool d = dfs(r, c - 1);
            bool e = dfs(r, c + 1);

            return a && b && d && e;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j))
                        count++;
                }
            }
        }

        return count;
    }
};