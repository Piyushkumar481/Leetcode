class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[0] = 0;

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int node = -1;

            for(int j = 0; j < n; j++)
            {
                if(!visited[j] && (node == -1 || dist[j] < dist[node]))
                {
                    node = j;
                }
            }

            visited[node] = true;
            ans += dist[node];

            for(int j = 0; j < n; j++)
            {
                if(!visited[j])
                {
                    int cost = abs(points[node][0] - points[j][0])
                             + abs(points[node][1] - points[j][1]);

                    if(cost < dist[j])
                    {
                        dist[j] = cost;
                    }
                }
            }
        }

        return ans;
    }
};