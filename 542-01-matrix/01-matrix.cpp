class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                   dist[nr][nc] == -1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};