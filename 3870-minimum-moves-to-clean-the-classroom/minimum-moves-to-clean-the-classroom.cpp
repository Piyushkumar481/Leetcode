class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litter = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        int full = (1 << litter) - 1;

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litter, false)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if(mask == full)
                    return moves;

                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    if(e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if(classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    if(classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if(!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};