class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            graph[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(time > dist[node])
            {
                continue;
            }

            for(auto x : graph[node])
            {
                int next = x.first;
                int weight = x.second;

                if(time + weight < dist[next])
                {
                    dist[next] = time + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};