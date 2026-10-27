class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0, j = 0;
        grid[i][j] = '.';

        while (i < m - 1 || j < n - 1) {
            if (j < n - 1) {
                grid[i][j + 1] = '.';
                j++;
            } else {
                grid[i + 1][j] = '.';
                i++;
            }
        }

        return grid;
    }
};