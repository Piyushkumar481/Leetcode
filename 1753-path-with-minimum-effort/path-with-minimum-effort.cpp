class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while(!pq.empty())
        {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(r == m - 1 && c == n - 1)
            {
                return effort;
            }

            if(effort > dist[r][c])
            {
                continue;
            }

            for(int i = 0; i < 4; i++)
            {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int difference = abs(heights[r][c] - heights[nr][nc]);

                    int newEffort = max(effort, difference);

                    if(newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};