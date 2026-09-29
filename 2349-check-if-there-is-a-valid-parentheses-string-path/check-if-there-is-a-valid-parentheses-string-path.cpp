class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int r, int c, int balance) {
        if(balance < 0)
            return false;

        if(balance > m + n)
            return false;

        if(r == m - 1 && c == n - 1)
            return balance == 0;

        if(dp[r][c][balance] != -1)
            return dp[r][c][balance];

        if(r + 1 < m) {
            int next = balance;

            if(grid[r + 1][c] == '(')
                next++;
            else
                next--;

            if(solve(grid, r + 1, c, next))
                return dp[r][c][balance] = 1;
        }

        if(c + 1 < n) {
            int next = balance;

            if(grid[r][c + 1] == '(')
                next++;
            else
                next--;

            if(solve(grid, r, c + 1, next))
                return dp[r][c][balance] = 1;
        }

        return dp[r][c][balance] = 0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == ')')
            return false;

        if(grid[m - 1][n - 1] == '(')
            return false;

        if((m + n - 1) % 2 != 0)
            return false;

        dp = vector<vector<vector<int>>>(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return solve(grid, 0, 0, 1);
    }
};