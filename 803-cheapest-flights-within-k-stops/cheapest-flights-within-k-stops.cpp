class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            graph[u].push_back({v, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0;

        while(!q.empty() && stops <= k)
        {
            int size = q.size();

            vector<int> temp = dist;

            for(int i = 0; i < size; i++)
            {
                int city = q.front().first;
                int cost = q.front().second;

                q.pop();

                for(auto x : graph[city])
                {
                    int next = x.first;
                    int price = x.second;

                    if(cost + price < temp[next])
                    {
                        temp[next] = cost + price;
                        q.push({next, temp[next]});
                    }
                }
            }

            dist = temp;
            stops++;
        }

        if(dist[dst] == INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};